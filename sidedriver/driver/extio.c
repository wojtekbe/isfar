/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "debug.h"
#include "extio.h"
#include <math.h>



void extio_init(void)
{
	/*
	 *	SRV1	PA8
	 *	SRV2	PA11
	 *	G_ADC2	PC1
	 *	G_ADC1	PC0		ADC123_IN10 (ADC3)
	 *
	 */
	
	/* init PWMs */
	//TODO
	
	/* init G_ADC1 */
	//TODO

	/* init G_ADC2 */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER0_1;
	RCC->APB2ENR |= RCC_APB2ENR_ADC3EN;
	ADC3->SQR1 = 0; // one conversion in seq
	ADC3->SQR3 = (10 << (5 * 0)); // SQ1 -> IN2
	ADC3->CR2 |= ADC_CR2_ADON;
}


uint16_t extio_adc1_read()
{
	ADC3->CR2 |= ADC_CR2_SWSTART;
	while(!(ADC3->SR & ADC_SR_EOC));
	return ADC3->DR;
}
