/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"

void td_init(void);
void td_enable(void);
void td_disable(void);
void td_dir(uint8_t);
void td_pwm(int);
void EXTI15_10_IRQHandler(void);

void td_init()
{
	/*
	 * M2-PWM 	PB0 	TIM1_CH2N
	 * M2-ENA 	PB1 	out
	 * M2-INA 	PB2 	out
	 * MIN		PB10	in
	 * MAX		PB11	in
	 * M2-ENB 	PA6 	out
	 * M2-INB 	PA5 	out
	 * TRANS 	PC8 	TIM3_CH3
	 */

	// IOs
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER1_0; // M2-ENA
	GPIOB->MODER |= GPIO_MODER_MODER2_0; // M2-INA

	// TODO MIN MAX
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[2] |= (1 << 12);  // MAX
	//SYSCFG->EXTICR[2] |= (1 << 8); // PB10
	EXTI->IMR |= (1 << 11); // Interrupt Mask Reg.
	EXTI->FTSR |= (1 << 11); // MAX Falling Trigger
	//NVIC_EnableIRQ(EXTI15_10_IRQn);

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER6_0; // M2-ENB
	GPIOA->MODER |= GPIO_MODER_MODER5_0; // M2-INB


	// PWM: TIM1_CH2N (PB0/AF1)
	GPIOB->MODER |= GPIO_MODER_MODER0_1; // AF
	GPIOB->AFR[0] |= (1 << 0); // AF1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	TIM1->PSC =   10 - 1;
	TIM1->ARR =   100 - 1;
	TIM1->BDTR |= TIM_BDTR_MOE;
	TIM1->CCMR1 = TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1; // PWM mode for CH2
	TIM1->CCER = TIM_CCER_CC2NE;

	// TRANS ?
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	//GPIOC->MODER |= GPIO_MODER_MODER8_1;
}

void EXTI15_10_IRQHandler()  // td: MIN or MAX interrupt
{
	EXTI->PR = EXTI_PR_PR11;
	printf("EXTI\n");
}

void td_pwm(int width)
{
	if(width != TIM1->CCR2)
	{
		if(width == 0)
			TIM1->CR1 &= ~TIM_CR1_CEN;
		else
			TIM1->CR1 |= TIM_CR1_CEN;

		TIM1->CCR2 = width;
	}
}

void td_enable()
{
	GPIOB->ODR |= (1 << 1); // M2-ENA = 1
	GPIOA->ODR |= (1 << 6); // M2-ENB = 1
}

void td_disable()
{
	//debug("td_disable()\n");
	GPIOB->ODR &= ~(1 << 1); // M2-ENA = 0
	GPIOA->ODR &= ~(1 << 6); // M2-ENB = 0
}

void td_dir(uint8_t d)
{
	//debug("td_dir(%d)\n", d);

	if(d < 0x80) // water out
	{
		GPIOB->ODR |=  (1 << 2); // M2-INA = 1
		GPIOA->ODR &= ~(1 << 5); // M2-INB = 0
	}
	else // water in
	{
		GPIOB->ODR &= ~(1 << 2); // M2-INA = 0
		GPIOA->ODR |=  (1 << 5); // M2-INB = 1
	}
}
