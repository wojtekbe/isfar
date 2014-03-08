#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"
#include "core_cm4.h"
#include <stdio.h>
#include <unistd.h>

int _write(int, char*, int);

void _wait(uint32_t nCount)
{
  while(nCount--)
  {
	  __asm__("NOP");
  }
}

int _write(int file, char *ptr, int len)
{
	int i;

	if (file == STDOUT_FILENO || file == STDERR_FILENO) {
		for (i = 0; i < len; i++) {
			if (ptr[i] == '\n') {
				usart_send('\r');
			}
		usart_send(ptr[i]);
		}
		return i;
	}
	return -1;
}

void init_usart(void)
{	
	USART_InitTypeDef USART_InitStructure;

	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	GPIOA->MODER |= GPIO_MODER_MODER9_1;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR9_0;
	GPIOA->AFR[1] |= (7 << 4);

	USART_InitStructure.USART_BaudRate = 115200;	
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1, ENABLE); // enable USART1
}

void usart_send(uint8_t d)
{
	while ((USART1->SR & USART_SR_TXE) == 0);
	USART1->DR = d;
}

void init_timer2(void) // PA1 -> M1-PWM (TIM2_CH2)
{
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER1_1;
	GPIOA->AFR[0] |= (1 << 4);
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; 
	TIM2->PSC =   5;
	TIM2->ARR =   100;
	TIM2->CCR2 =  10;
	TIM2->CCMR1 = TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1; // Output Compare 2 Mode = 110 (PWM 1 Mode)
	TIM2->CCER = TIM_CCER_CC2E; // Capture/Compare 2 output enable
	TIM2->CR1 |= TIM_CR1_CEN; // Counter Enable
}

void init_ledd(void)
{
	// PC9 -> LED-PWM (TIM3_CH4)
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER9_1;
	GPIOC->AFR[1] |= (2 << 4); // AF2
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; 
	TIM3->PSC =   0;
	TIM3->ARR =   9;
	TIM3->CCR4 =  2;
	TIM3->CCMR2 = TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1; // Output Compare 4 Mode = 110 (PWM 1 Mode)
	TIM3->CCER = TIM_CCER_CC4E; // Capture/Compare 4 output enable
	TIM3->CR1 |= TIM_CR1_CEN; // Counter Enable
	// SRV1 -> PA8 (TIM1_CH1)
	// SRV2 -> PA11 (TIM1_CH1)
}

int main(void)
{
	init_usart();
	init_timer2();
	init_ledd();
	printf("Hello\n");
	while(1){
	}
}
