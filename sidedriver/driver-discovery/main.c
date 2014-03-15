#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"
#include "core_cm4.h"
#include <stdio.h>
#include <unistd.h>

#define GREEN 12
#define ORANGE 13
#define RED 14
#define BLUE 15
#define LED(n,s) if(s) GPIOD->BSRRL |= (1 << n); else GPIOD->BSRRH |= (1 << n);
#define LEDT(n) GPIOD->ODR ^= (1<<n);

int _write(int, char*, int);
void init_leds(void);
void init_usart(void);
void usart_send(uint8_t);
void init_timer4(void);
void init_timer3(void);
void init_i2c(void);
void wait(uint32_t);

uint16_t i2c_regs[4] = {0, 0, 0, 0};
int i2c_bytes_received;
int i2c_reg_idx;

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
	//errno = EIO;
	return -1;
}

void init_leds(void)
{
	// PD11-15 as outputs
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODER11_0;
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

void init_timer4(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; 
	GPIOD->MODER |= GPIO_MODER_MODER13_1;
	GPIOD->AFR[1] |= (2 << 20);
	TIM4->PSC =   16799;
	TIM4->ARR =   99;
	TIM4->CCR2 =  50;
	TIM4->CCMR1 = TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; // Output Compare 2 Mode = 110 (PWM 1 Mode)
	TIM4->CCER |= TIM_CCER_CC2E; // Capture/Compare 2 output enable
	TIM4->CR1 |= 0 | TIM_CR1_CEN;
}

void init_timer3()
{
	// Capturing on PC6
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	GPIOC->MODER |= GPIO_MODER_MODER6_1; // AF for PC6
	GPIOC->AFR[0] |= (2 << 24); // AF2 for PC6
	TIM3->PSC = 10000-1;
	TIM3->ARR = 1000-1;
	TIM3->CCMR1 |= TIM_CCMR1_CC1S_0; // CC1 channel is conf. as INPUT, IC1 is mapped on TI1
	TIM3->CCER |= TIM_CCER_CC1E; 
	TIM3->CR1 |= TIM_CR1_CEN;
}

void init_i2c(void) 
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	GPIOB->OTYPER |= (1 << 7) | (1 << 8); // Open drain PB7,8
	GPIOB->PUPDR |= GPIO_PUPDR_PUPDR7_0 | GPIO_PUPDR_PUPDR8_0; // Enable Pull-Ups for PB7,8
	GPIOB->MODER |= GPIO_MODER_MODER7_1 | GPIO_MODER_MODER8_1;
	GPIOB->AFR[0] |= (4 << 28); // AF4 for PB7 SDA
	GPIOB->AFR[1] |= (4 << 0);  // AF4 for PB8 SCL
	I2C1->OAR1 = (0x09 << 1) | (1 << 14);
	NVIC_EnableIRQ(I2C1_EV_IRQn); // Enable I2C1 EV IRQ
	NVIC_EnableIRQ(I2C1_ER_IRQn); // Enable I2C1 ER IRQ
	I2C1->CR2 |= I2C_CR2_ITERREN | I2C_CR2_ITEVTEN | I2C_CR2_ITBUFEN; 
	I2C1->CR1 |= I2C_CR1_ACK | I2C_CR1_PE;

	i2c_reg_idx = 0;
	i2c_bytes_received = 0;
}


void I2C1_EV_IRQHandler() 
{
	uint16_t temp;
	uint16_t stat1 = 0;
	//uint16_t stat2 = 0;
	uint32_t data;

	stat1 = I2C1->SR1;
	//stat2 = I2C1->SR2;

	if(stat1 & I2C_SR1_ADDR) // ADDR matched, EV1
	{
		temp = I2C1->SR1;
		temp = I2C1->SR2;
		i2c_bytes_received = 0;
	}
	
	if(stat1 & I2C_SR1_RXNE) // Recv. reg. not empty EV2
	{		
		data = I2C1->DR;
		i2c_bytes_received++;
		if(i2c_bytes_received == 1)
			i2c_reg_idx = data;
		else
			i2c_regs[i2c_reg_idx] = data;
	}
	
	if(stat1 & I2C_SR1_TXE) // Transm. reg. empty
	{	
		I2C1->DR = i2c_regs[i2c_reg_idx];
	}	
	
	if(stat1 & I2C_SR1_BTF) // Byte Transfer Finished
	{
		LED(ORANGE, 1);
	}
	
	if(stat1 & I2C_SR1_STOPF) // STOP received, EV4
	{
		// clear this flag
		temp = I2C1->SR1;
		I2C1->CR1 |= I2C_CR1_PE;
	}
}

void I2C1_ER_IRQHandler() 
{
	uint16_t stat1 = 0;
	//uint16_t stat2 = 0;

	stat1 = I2C1->SR1;
	//stat2 = I2C1->SR2;

	LED(RED, 1);
	
	if(stat1 & I2C_SR1_AF) // ACK failure (NACK)
	{
		I2C1->SR1 &= ~I2C_SR1_AF;
		LED(RED, 0);
	}
	
	if(stat1 & I2C_SR1_OVR) // Overflow
	{
		I2C1->SR1 &= ~I2C_SR1_OVR;
		LED(RED, 0);
	}
}

void wait(uint32_t nCount)
{
  while(nCount--)
  {
	  __asm__("NOP");
  }
}

int main(void)
{
	int i;

	init_leds();
	init_usart();
	//init_timer3();
	init_i2c();
	printf("Hello\n");
	while(1)
	{	
		printf("[");
		for(i = 0; i <= 4; i++)
		{
			if(i2c_reg_idx == i)
				printf("*");
			printf("%d ", i2c_regs[i] );
		}
		printf("]\n");
		wait(6000000);
	}
}
