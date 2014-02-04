#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"

#define LED(n,s) if(s) GPIOD->BSRRL |= (1 << n); else GPIOD->BSRRH |= (1 << n);
#define LEDT(n) GPIOD->ODR ^= (1<<n);

void init_leds(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODER12_0;
	GPIOD->MODER |= GPIO_MODER_MODER13_0;
	GPIOD->MODER |= GPIO_MODER_MODER14_0;
	GPIOD->MODER |= GPIO_MODER_MODER15_0;
}

void init_usart(void)
{	
	USART_InitTypeDef USART_InitStructure;

	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	GPIOA->MODER |= GPIO_MODER_MODER2_1;
	//GPIOA->PUPDR |= GPIO_PUPDR_PUPDR2_0;
	GPIOA->AFR[0] |= 0x0000700;

	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_Init(USART2, &USART_InitStructure);
	USART_Cmd(USART2, ENABLE); // enable USART2
}

void usart_send(uint8_t d)
{
	while ((USART2->SR & USART_SR_TXE) == 0);
	USART2->DR = d;
}

void usart_send_uint16(uint16_t i)
{
	while ((USART2->SR & USART_SR_TXE) == 0);
	USART2->DR = (i >> 8);
	while ((USART2->SR & USART_SR_TXE) == 0);
	USART2->DR = i;
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
	I2C1->OAR1 = (0x08 << 1);
	I2C1->CR1 |= I2C_CR1_ACK | I2C_CR1_PE;
}

void Delay(__IO uint32_t nCount)
{
  while(nCount--)
  {
  }
}

int main(void)
{
	init_leds();
	init_usart();
	//init_timer4();
	//init_i2c();
	while(1){
		LEDT(12);
		usart_send_uint16(0x1234);
		//usart_send(0x20);
		//USART_SendData(USART2, 0x12);
		//if(I2C1->SR1 & I2C_SR1_ADDR) 
		//	LED(12, 1)
		//else 
		//	LED(12, 0)
		Delay(1000000);
	}
}
