/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "tankdriver.h"
#include <debug.h>


/* private */
void TIM1_BRK_TIM9_IRQHandler(void);
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
	 * TRANS 	PA3 	TIM9_CH2
	 *
	 * TIM1     PWM
	 * TIM9     TRANSOPT.
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

	//td_reset();

	/* TRANSOPT. TIM9_CH2 (PA3/AF3) */
	/* generate interrupt on falling edge on PA3 */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER3_1; // AF
	GPIOA->AFR[0] |= (0x03 << (4 * 3)); // AF3
	NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);
	RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
	TIM9->PSC = 0;
	TIM9->ARR = 0xFFFF - 1;
	TIM9->CCMR1 |= TIM_CCMR1_CC2S_0 | TIM_CCMR1_IC2F_2; /* input capture on chann. 3, filter */
	TIM9->CCER |= TIM_CCER_CC2E | TIM_CCER_CC2P; /* Enable input chann. 3, detect falling edges */
	TIM9->DIER |= TIM_DIER_CC2IE; /* Enable interrupt */
	TIM9->CR1 |= TIM_CR1_CEN;
	TIM9->EGR |= TIM_EGR_UG; /* Force update */
	td_pos = 0;
	td_cpos = 0;
	td_set_dir(0);

	while((TIM9->SR & TIM_SR_CC2IF) == 0);
	debug("td_init exit\n");
}

void TIM1_BRK_TIM9_IRQHandler(void)  /* Transoptor IRQ */
{
	debug("irq\n");
	if(TIM9->SR & TIM_SR_CC2IF) {
		td_cpos += td_dir;
		//debug("%d %d %d %x\n", (int)td_pos, (int)td_cpos, (int)td_dir, ((GPIOB->IDR & (1 << 10)) ? 1 : 0));
		if (MIN == 0)
			td_cpos = 0;
		//if ((GPIOB->IDR & (1 << 11))) {
		//	td_set_dir(0);
		//}
		if (td_cpos == td_pos)
			td_set_dir(0);
		TIM9->SR &= ~TIM_SR_CC3IF;
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
