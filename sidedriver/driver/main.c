#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"

void _wait(__IO uint32_t i)
{
  while(i--) { }
}

void init_usart(void)
{	
	USART_InitTypeDef USART_InitStructure;

	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	GPIOA->MODER |= GPIO_MODER_MODER9_1;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR9_0;
	GPIOA->AFR[1] |= (7 << 4);

	//USART2->BRR = 0x000100E5;
	//USART2->CR1 |= USART_CR1_TE | USART_CR1_UE;
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	USART_Cmd(USART1, ENABLE);
}

/*
void usart_send_uint16(uint16_t i)
{
	//USART_SendData(USART2, (uint8_t)((i >> 24) & 0x000000FF));
	//USART_SendData(USART2, (uint8_t)((i >> 16) & 0x000000FF));
	USART_SendData(USART2, (uint8_t)((i >> 8) & 0x00FF));
	USART_SendData(USART2, (uint8_t)(i & 0x00FF));
}
*/

void init_timer2(void) // PA1 -> M1-PWM
{
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER1_1;
	GPIOA->AFR[0] |= (1 << 4);
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; 
	TIM2->PSC =   5;
	TIM2->ARR =   100;
	TIM2->CCR2 =  10;
	TIM2->CCMR1 = TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; // Output Compare 2 Mode = 110 (PWM 1 Mode)
	TIM2->CCER = TIM_CCER_CC2E; // Capture/Compare 2 output enable
	TIM2->CR1 |= TIM_CR1_CEN; // Counter Enable
}


int main(void)
{
	init_usart();
	init_timer2();
	while(1){
		USART_SendData(USART1, 'a');
		_wait(0xFFFFF);
	}
}
