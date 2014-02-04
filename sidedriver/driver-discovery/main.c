#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"

void init_usart(void)
{	
	USART_InitTypeDef USART_InitStructure;

	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	GPIOA->MODER |= GPIO_MODER_MODER2_1;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR2_0;
	GPIOA->AFR[0] |= 0x0000700;

	//USART2->BRR = 0x000100E5;
	//USART2->CR1 |= USART_CR1_TE | USART_CR1_UE;
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);
	USART_Cmd(USART2, ENABLE); // enable USART2
}

void usart_send_uint16(uint16_t i)
{
	//USART_SendData(USART2, (uint8_t)((i >> 24) & 0x000000FF));
	//USART_SendData(USART2, (uint8_t)((i >> 16) & 0x000000FF));
	USART_SendData(USART2, (uint8_t)((i >> 8) & 0x00FF));
	USART_SendData(USART2, (uint8_t)(i & 0x00FF));
}

void init_timer4(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; 
	GPIOD->MODER |= GPIO_MODER_MODER13_1;
	GPIOD->AFR[1] |= (2 << 20);
	TIM4->PSC =   5;
	TIM4->ARR =   100;
	TIM4->CCR2 =  10;
	TIM4->CCMR1 = TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; // Output Compare 2 Mode = 110 (PWM 1 Mode)
	TIM4->CCER |= TIM_CCER_CC2E; // Capture/Compare 2 output enable
	TIM4->CR1 =   TIM_CR1_CEN;
}

void init_i2c(void) 
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	GPIOB->MODER |= GPIO_MODER_MODER7_1 | GPIO_MODER_MODER8_1;
	GPIOB->AFR[0] |= (4 << 28); // AF4 for PB7
	GPIOB->AFR[1] |= (4 << 0);  // AF4 for PB8
	I2C1->OAR1 = 0x18;
	I2C1->CR1 |= I2C_CR1_ACK | I2C_CR1_ENGC | I2C_CR1_PE;
}

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

int main(void)
{
	init_usart();
	//init_timer4();
	init_i2c();
	while(1){
		USART_SendData(USART2, 'a');
		Delay(0x3FFFFF);
	}
}
