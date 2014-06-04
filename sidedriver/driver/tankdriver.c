/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "tankdriver.h"
#include <debug.h>


/* private */
void TIM3_IRQHandler(void);
void td_set_pwm(uint32_t);

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

	/* IOs */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER1_0; /* M2-ENA */
	GPIOB->MODER |= GPIO_MODER_MODER2_0; /* M2-INA */

	/* TODO MIN MAX */
	//RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	//SYSCFG->EXTICR[2] |= (1 << 12);  /* MAX */
	//SYSCFG->EXTICR[2] |= (1 << 8); // PB10
	//EXTI->IMR |= (1 << 11); // Interrupt Mask Reg.
	//EXTI->FTSR |= (1 << 11); // MAX Falling Trigger
	//NVIC_EnableIRQ(EXTI15_10_IRQn);

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER6_0; /* M2-ENB */
	GPIOA->MODER |= GPIO_MODER_MODER5_0; /* M2-INB */

	/* PWM: TIM1_CH2N (PB0/AF1) */
	GPIOB->MODER |= GPIO_MODER_MODER0_1; // AF
	GPIOB->AFR[0] |= (1 << 0); // AF1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	TIM1->PSC =   10 - 1;
	TIM1->ARR =   100 - 1;
	TIM1->BDTR |= TIM_BDTR_MOE;
	TIM1->CCMR1 = TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1; // PWM mode for CH2
	TIM1->CCER = TIM_CCER_CC2NE;

	td_reset();

	/* TRANSOPT. TIM3_CH3 (PC8/AF2) */ 
	/* TODO better use ext. interrupt */
	/* TODO even better: use as timer source */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER8_1; // AF
	GPIOC->AFR[1] |= 0x02; // AF2
	NVIC_EnableIRQ(TIM3_IRQn);
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC = 0;
	TIM3->ARR = 0xFFFF - 1;	
	TIM3->CCMR2 |= TIM_CCMR2_CC3S_0 | TIM_CCMR2_IC3F_2; /* input capture on chann. 3, filter */
	TIM3->CCER |= TIM_CCER_CC3E | TIM_CCER_CC3P; /* Enable input chann. 3, detect falling edges */
	TIM3->DIER |= TIM_DIER_CC3IE; /* Enable interrupt */ 
	TIM3->CR1 |= TIM_CR1_CEN;
	TIM3->EGR |= TIM_EGR_UG; /* Force update */
	td_pos = 0;
	td_cpos = 0;
	td_set_dir(0);

	debug("td_init exit\n");
}

void TIM3_IRQHandler(void)  /* Transoptor IRQ */
{
	if(TIM3->SR & TIM_SR_CC3IF) {
		td_cpos += td_dir;
		debug("%d %d %d %x\n", td_pos, td_cpos, td_dir, ((GPIOB->IDR & (1 << 10)) ? 1 : 0));
		if (MIN == 0)
			td_cpos = 0;
		//if ((GPIOB->IDR & (1 << 11))) {
		//	td_set_dir(0);
		//}
		if (td_cpos == td_pos)
			td_set_dir(0);
		TIM3->SR &= ~TIM_SR_CC3IF;
	}
}

void td_set_pos(int p)
{
	//debug("td_set_pos()\n");
	int dpos = p - td_cpos;
	td_pos = p;
	if (dpos) {
		td_set_pwm(20);
		td_set_dir(dpos);
	}
}

void td_reset()
{
	td_enable();
	td_set_dir(WATER_OUT);
	td_set_pwm(15);
	
	while((GPIOB->IDR & (1 << 10)) != 0)
		debug("resetting ... \n");
	
	td_set_pwm(0);
	td_set_dir(0);
	td_disable();
}

void td_set_pwm(uint32_t width)
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

void td_set_dir(int32_t d)
{
	if (d == 0) {
		td_dir = 0;
		GPIOB->ODR &= ~(1 << 2); // M2-INA = 0
		GPIOA->ODR &= ~(1 << 5); // M2-INB = 0
	}
	else if(d < 0) { // water out
		td_dir = WATER_OUT;
		GPIOB->ODR |=  (1 << 2); // M2-INA = 1
		GPIOA->ODR &= ~(1 << 5); // M2-INB = 0
	}
	else { // water in
		td_dir = WATER_IN;
		GPIOB->ODR &= ~(1 << 2); // M2-INA = 0
		GPIOA->ODR |=  (1 << 5); // M2-INB = 1
	}
}
