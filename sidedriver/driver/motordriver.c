/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "debug.h"
#include "motordriver.h"
//#include <math.h>

void md_init(void)
{
	/*
	 * M1-PWM 	PA1 	TIM2_CH2
	 * M1-CS 	PA2 	ADC123_IN2
	 * M1-ENB 	PA3 	out
	 * M1-INB 	PA4 	out
	 * M1-INA 	PC2 	out
	 * M1-ENA 	PC3 	out
	 * ENC1 	PC6 	TIM8_CH1
	 * ENC2 	PC7 	TIM8_CH2
	 */
	
	//debug("md_init()\n");

	/* IOs */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER3_0; // M1-ENB
	GPIOA->MODER |= GPIO_MODER_MODER4_0; // M1-INB
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER2_0; // M1-INA
	GPIOC->MODER |= GPIO_MODER_MODER3_0; // M1-ENA

	/* PWM: TIM2_CH2 (PA1/AF1) */
	GPIOA->MODER |= GPIO_MODER_MODER1_1; // AF
	GPIOA->AFR[0] |= (1 << 4); // AF1
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC =   83;
	TIM2->ARR =   99; // 10 kHz
	TIM2->CCMR1 = TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1;
	TIM2->CCER = TIM_CCER_CC2E;

	/* Encoder: counting tics: TIM8_CH1/2 (PC6/7 AF3) */
	GPIOC->MODER |= GPIO_MODER_MODER6_1; // PC6 -> AF
	GPIOC->AFR[0] |= (3 << 24); // PC6 -> AF3
	GPIOC->MODER |= GPIO_MODER_MODER7_1; // PC7 -> AF
	GPIOC->AFR[0] |= (3 << 28); // PC7 -> AF3
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
	TIM8->ARR = 0xFFFF;
	TIM8->PSC = 2 - 1; // (Prescaler - 1)
	TIM8->CCMR1 = TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0; // CC1S = 01, CC2S = 02 (inputs)
	TIM8->CCER |= TIM_CCER_CC1P | TIM_CCER_CC2P; // CC1P = 1, CC2P = 1 input polarity
	TIM8->SMCR |= TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0; // Slave Mode, SMS = 011, Encoder Mode 3 p. 615
	TIM8->EGR |= TIM_EGR_UG; /* Force update */
	TIM8->CR1 |= TIM_CR1_CEN;
	TIM8->SR &= ~0x1; /* Clear update flag */

	/* Calculate speed using TIM4 interrupt */
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4->PSC = 8400 - 1;
	TIM4->ARR = 200 - 1;
	TIM4->DIER = TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM4_IRQn);
	TIM4->EGR |= TIM_EGR_UG; /* Force update */
	TIM4->CR1 |= TIM_CR1_CEN;
	md_enc_upd_ms = ( ((TIM4->PSC+1)*(TIM4->ARR+1)) / 84000 );
	md_cpos = 0;
	md_lpos = 0;
	md_w = 0;

	/* TODO Current measure: M1-CS */
	GPIOA->MODER |= GPIO_MODER_MODER2_0 | GPIO_MODER_MODER2_1;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//ADC->CR1 |=
	//ADC->CR2 |= ADC_CR2_ADON;


	// debug("md_init OK\n");
}

void TIM4_IRQHandler(void)  /* Encoder IRQ */
{
	if(TIM4->SR & TIM_SR_UIF)
	{
		md_cpos = TIM8->CNT;

		if (TIM8->SR & 0x01) {
			md_w = (int16_t)(md_cpos + 0xFFFF - md_lpos) * 30 / 4; /* [RPM] */
			TIM8->SR &= ~0x01;
		}
		else
			md_w = (int16_t)(md_cpos - md_lpos) * 30 / 4; /* RPM] */

		md_lpos = md_cpos;
	}
	TIM4->SR &= ~TIM_SR_UIF;
}

void md_set_speed(int16_t w)
{
	uint16_t pwm;
	if (w > M1_MAX_SPEED)
		w = M1_MAX_SPEED;

	if (w < -M1_MAX_SPEED)
		w = -M1_MAX_SPEED;

	pwm = (abs(w) * (TIM2->ARR + 1) / M1_MAX_SPEED);

	if (w == 0) {
		TIM2->CR1 &= ~TIM_CR1_CEN; // stop counting/pwm
		TIM2->CCR2 = 0;
	} else if (w > 0) {
		TIM2->CCR2 = pwm;
		TIM2->CR1 |= TIM_CR1_CEN; // pwm start
		GPIOC->ODR |=  (1 << 2); // M1-INA = 1
		GPIOA->ODR &= ~(1 << 4); // M1-INB = 0
	} else {
		TIM2->CCR2 = pwm;
		TIM2->CR1 |= TIM_CR1_CEN; // pwm start
		GPIOC->ODR &= ~(1 << 2); // M1-INA = 0
		GPIOA->ODR |=  (1 << 4); // M1-INB = 1
	}
}

void md_enable()
{
	// debug("md_enable()\n");

	GPIOC->ODR |= (1 << 3); // M1-ENA = 1
	GPIOA->ODR |= (1 << 3); // M1-ENB = 1
}

void md_disable()
{
	//debug("md_disable()\n");

	GPIOC->ODR &= ~(1 << 3); // M1-ENA = 0
	GPIOA->ODR &= ~(1 << 3); // M1-ENB = 0
}

/*
void md_dir(uint8_t dir)
{
	//debug("md_dir(%d)\n", dir);

	if(dir < 0x80)
	{
		GPIOC->ODR |=  (1 << 2); // M1-INA = 1
		GPIOA->ODR &= ~(1 << 4); // M1-INB = 0
	}
	else
	{
		GPIOC->ODR &= ~(1 << 2); // M1-INA = 0
		GPIOA->ODR |=  (1 << 4); // M1-INB = 1
	}
}
*/
/*
void md_pwm(uint32_t width)
{
	//debug("md_pwm(%d)\n", PWM);

	if (width != TIM2->CCR2) {
		if (width == 0)
			TIM2->CR1 &= ~TIM_CR1_CEN;
		else
			TIM2->CR1 |= TIM_CR1_CEN;

		TIM2->CCR2 = width;
	}
}
*/

