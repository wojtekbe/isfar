/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "tinyprintf.h"
#include <unistd.h>
#include "debug.h"

void debug_init(void)
{
	/*
	 * TX 	PA9 	USART1_TX
	 * RX 	PA10 	USART1_RX
	 * LED  PA12	output
	 */
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER9_1;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR9_0;
	GPIOA->AFR[1] |= (7 << 4);
	USART1->BRR = 0x2D9; // 115200
	USART1->CR3 |= USART_CR3_ONEBIT; // Doesn't work without that...
	USART1->CR1 |= USART_CR1_TE | USART_CR1_UE;

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER12_0;

	init_printf(NULL, usart_send);
}

void usart_send(void* p, char c)
{
	(void)p; /* suppress warning */
	while ((USART1->SR & USART_SR_TXE) == 0);
	USART1->DR = c;
}
