#include "stm32f4xx.h"
#include "stm32f4xx_usart.h"
#include "core_cm4.h"
#include <stdio.h>
#include <unistd.h>

void _wait(uint32_t);
void init_usart(void);
int _write(int, char*, int);
void usart_send(uint8_t);
void init_motord(void);
void init_ledd(void);

void tankd_init(void);
void tankd_enable(void);
void tankd_disable(void);
void tankd_dir(int);
void tankd_sp(int);

struct tankd_state
{
	int init;
	int enabled;
	int dir;
	int piston_pos;	
};

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
	/*
	 * TX 	PA9 	USART1_TX
	 * RX 	PA10 	USART1_RX
	 */

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

void init_motord(void)
{
	/*
	 * M1-PWM 	PA1 	TIM2_CH2
	 * M1-CS 	PA2 	ADC123_IN2
	 * M1-ENA 	PC3 	out
	 * M1-ENB 	PA3 	out
	 * M1-INA 	PC3 	out
	 * M1-INB 	PA4 	out
	 * ENC1 	PC6 	TIM8_CH1
	 * ENC2 	PC7 	TIM8_CH2
	 */
	
	// PWM: TIM2_CH2 (PA1/AF1)
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER1_1;
	GPIOA->AFR[0] |= (1 << 4);
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; 
	TIM2->PSC =   83;
	TIM2->ARR =   99;
	TIM2->CCR2 =  10;
	TIM2->CCMR1 = TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1;
	TIM2->CCER = TIM_CCER_CC2E;
	TIM2->CR1 |= TIM_CR1_CEN;

	/*
	// Encoder: TIM8_CH1/2 (PC6/7 AF3)
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER6_1; // PC6 -> AF
	GPIOC->AFR[0] |= (3 << 24); // PC6 -> AF3
	GPIOC->MODER |= GPIO_MODER_MODER7_1; // PC7 -> AF
	GPIOC->AFR[0] |= (3 << 28); // PC7 -> AF3
	TIM8->PSC = 0;
	TIM8->ARR = 0xFFFF;
	TIM8->CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0; // CC1S = 01, CC2S = 02 (inputs)
	TIM8->SMCR |= TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0; // Slave Mode, SMS = 011, Encoder Mode 3 p. 615
	TIM8->CCER |= TIM_CCER_CC1P | TIM_CCER_CC2P; // CC1P = 1, CC2P = 1
	TIM8->CR1 |= TIM_CR1_CEN;
	*/
}

void tankd_init()
{
	/*
	 * M2-PWM 	PB0 	TIM1_CH2N
	 * M2-ENA 	PB1 	out
	 * M2-INA 	PB2 	out
	 * MIN		PB10	in
	 * MAX		PB11	in
	 * M2-ENB 	PA6 	out
	 * M2-INB 	PA5 	out
	 * TRANS 	PC8 	? TODO
	 */

	// IOs
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER1_0; // M2-ENA
	GPIOB->MODER |= GPIO_MODER_MODER2_0; // M2-INA
	GPIOB->MODER |= GPIO_MODER_MODER10_0; // MIN
	GPIOB->MODER |= GPIO_MODER_MODER11_0; // MAX
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; 
	GPIOA->MODER |= GPIO_MODER_MODER6_0; // M2-ENB
	GPIOA->MODER |= GPIO_MODER_MODER5_0; // M2-INB

	// PWM: TIM1_CH2N (PB0/AF1)
	// TODO: temp. changed to TIM3_CH3
	GPIOB->MODER |= GPIO_MODER_MODER0_1;
	GPIOB->AFR[0] |= (2 << 0);
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN; 
	TIM3->PSC =   9;
	TIM3->ARR =   99;
	//TIM3->CCR3 =  25;
	TIM3->CCMR2 = TIM_CCMR2_OC3M_2 | TIM_CCMR2_OC3M_1; // PWM mode
	TIM3->CCER = TIM_CCER_CC3E;
	//TIM3->CR1 |= TIM_CR1_CEN;
	
	// TRANS ? 
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	//GPIOC->MODER |= GPIO_MODER_MODER8_1;
}

void tankd_sp(int sp)
{
	TIM3->CCR3 = sp;
	
	if(sp == 0)
		TIM3->CR1 &= ~TIM_CR1_CEN;
	else
		TIM3->CR1 |= TIM_CR1_CEN;		
}

void tankd_enable()
{
	GPIOB->ODR |= (1 << 1); // M2-ENA = 1
	GPIOA->ODR |= (1 << 6); // M2-ENB = 1
}

void tankd_disable()
{
	GPIOB->ODR &= ~(1 << 1); // M2-ENA = 0
	GPIOA->ODR &= ~(1 << 6); // M2-ENB = 0
}

void tankd_dir(int d)
{
	printf("td: dir=%d\n", d);
	
	if(d == 0) // stop
	{
		GPIOB->ODR &= ~(1 << 2); // M2-INA = 0
		GPIOA->ODR &= ~(1 << 5); // M2-INB = 0
	}
	else if(d < 0) // water out
	{
		GPIOB->ODR |=  (1 << 2); // M2-INA = 1
		GPIOA->ODR &= ~(1 << 5); // M2-INB = 0
	}
	else // water in
	{
		GPIOB->ODR &= ~(1 << 2); // M2-INA = 0
		GPIOA->ODR |=  (1 << 5); // M2-INB = 1
	}
}


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

int main(void)
{	
	init_usart();
	//init_motord();
	tankd_init();
	tankd_enable();
	tankd_sp(10);
	tankd_dir(-1);
	//init_ledd();
	printf("Hello\n");
	while(1){
	}
}
