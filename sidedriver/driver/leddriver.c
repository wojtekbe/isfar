/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "debug.h"

void init_ledd(void);

void init_ledd(void)
{
	/*
	 * SRV1 	PA8 	? TODO
	 * SRV2 	PA11 	? TODO
	 * LED-PWM 	PC9 	TIM3_CH4
	 */

	// PWM TIM3_CH4 PC9/AF2
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER9_1;
	GPIOC->AFR[1] |= (2 << 4);
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC =   5;
	TIM3->ARR =   100;
	TIM3->CCR4 =  10;
	TIM3->CCMR2 = TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1; // Output Compare 4 Mode = 110 (PWM 1 Mode)
	TIM3->CCER = TIM_CCER_CC4E; // Capture/Compare 4 output enable
	TIM3->CR1 |= TIM_CR1_CEN; // Counter Enable
}

