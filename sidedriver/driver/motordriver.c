/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "debug.h"
#include "motordriver.h"
#include <stdlib.h>

#define PID_MAX_U 3370
#define M1_MAX_SPEED 3370

void pid_init(void);
void TIM4_IRQHandler(void); /* Calculate speed isr */
void TIM5_IRQHandler(void); /* PID isr */

int md_enc_upd_ms;

void md_init(void)
{
	/*
	 * M1-PWM 	PA1 	TIM2_CH2
	 * M1-CS 	PA2 	ADC123_IN2
	 * M1-ENB 	PA0 	out
	 * M1-INB 	PA4 	out
	 * M1-INA 	PC2 	out
	 * M1-ENA 	PC3 	out
	 * ENC1 	PC6 	TIM8_CH1
	 * ENC2 	PC7 	TIM8_CH2
	 *
	 * TIM2     PWM
	 * TIM4     calculate speed isr
	 * TIM5     PID isr
	 * TIM8     encoder
	 */

	debug("#md_init()\n");

	/* IOs */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER0_0; // M1-ENB
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
	md_w_ref = 0;

	/* TODO Current measure: M1-CS */

	/* define PID inputs, init PID */
	pid.x = &md_w;
	pid.x_ref = &md_w_ref;
	pid_init();

	debug("md_init OK\n");
}

void TIM4_IRQHandler(void)  /* Encoder IRQ */
{
	if(TIM4->SR & TIM_SR_UIF)
	{
		md_cpos = TIM8->CNT;

		if (TIM8->SR & 0x01) { // counter overflow/underflow
			md_w = (int16_t)(md_cpos + 0xFFFF - md_lpos) * 30 / 4; /* [RPM] */
			TIM8->SR &= ~0x01;
		}
		else
			md_w = (int16_t)(md_cpos - md_lpos) * 30 / 4; /* [RPM] */

		md_lpos = md_cpos;
	}
	TIM4->SR &= ~TIM_SR_UIF;
}

void md_set_speed(int16_t w)
{
	uint16_t pwm;

	//debug("%s(%d)\n", __func__, w);

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

void pid_init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	TIM5->PSC = 8400 - 1;
	TIM5->ARR = 2000 - 1;
	TIM5->DIER = TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM5_IRQn);
	TIM5->CR1 |= TIM_CR1_CEN; // PID start

	pid.Kp = 1; /* Kp/10 */
	pid.Kd = 1;
	pid.Ki = 400;
	pid.Tp = (((TIM5->PSC+1)*(TIM5->ARR+1)) / 84000); // in ms
	pid.last_e = 0;
	pid.sum_of_e = 0;
	pid.enabled = 1;

	debug("#pid_init OK Kp = %d/10, Kd = %d, Ki = %d\n", (int)pid.Kp, (int)pid.Kd, (int)pid.Ki);
}

void TIM5_IRQHandler(void) /* PID IRQ */
{
	if(TIM5->SR & TIM_SR_UIF) {
		pid.e = *pid.x_ref - *pid.x;
		pid.sum_of_e += pid.e;
		pid.u = pid.Kp * (
				pid.e +
				(pid.Tp * pid.sum_of_e / pid.Ki) +  /* integr. */
				(pid.Kd * (pid.e - pid.last_e) / pid.Tp) /* diff */
				) / 10;

		/* limit u */
		if (pid.u > PID_MAX_U)
			pid.u = PID_MAX_U;
		if (pid.u < -PID_MAX_U)
			pid.u = -PID_MAX_U;

		pid.last_e = pid.e;

		/* set the speed */
		md_set_speed(pid.u);
	}
	TIM5->SR &= ~TIM_SR_UIF;

}

void md_enable()
{
	// debug("md_enable()\n");

	GPIOC->ODR |= (1 << 3); // M1-ENA = 1
	GPIOA->ODR |= (1 << 0); // M1-ENB = 1
}

void md_disable()
{
	//debug("md_disable()\n");

	GPIOC->ODR &= ~(1 << 3); // M1-ENA = 0
	GPIOA->ODR &= ~(1 << 0); // M1-ENB = 0
}
