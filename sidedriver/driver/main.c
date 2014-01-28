#include "stm32f4xx.h"
//#include "core_cm4.h"

void _wait(int);
//int fputc(int c, FILE *stream);

/*int fputc(int c, FILE *stream) 
{	
	USART1->DR = c;
	_wait(100);
	return c;
}
*/

void _wait(int c)
{
	int i;
	for (i = 0; i < c; i++) 
		__asm__("nop");
}

void init_gpio(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;	
	// PA4
	GPIOA->MODER |= GPIO_MODER_MODER4_0;
	// PD12
	GPIOD->MODER |= GPIO_MODER_MODER12_0;
}

void init_usart(void) 
{
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	GPIOA->MODER |= GPIO_MODER_MODER9_1;
	GPIOA->AFR[9] |= 7;
	USART1->BRR  = 0x0000008B; // 115200 kbps (!)
	USART1->CR1 |= USART_CR1_TE | USART_CR1_UE;
}
/*
void init_timer6(void)
{
	GPIOD->MODER |= GPIO_MODER_MODER15_0; // Enable output mode for D15 
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN; // Enable TIM6 clock 
	TIM6->PSC = 41999; // Set prescaler to 41999 
	TIM6->ARR = 5999; // Set auto-reload to 5999 
	TIM6->CR1 |= TIM_CR1_OPM; // One pulse mode 
	TIM6->EGR |= TIM_EGR_UG; // Force update 
	TIM6->SR &= ~TIM_SR_UIF; // Clear the update flag 
	TIM6->DIER |= TIM_DIER_UIE; // Enable interrupt on update event 
	NVIC_EnableIRQ(TIM6_DAC_IRQn); // Enable TIM6 IRQ 
	TIM6->CR1 |= TIM_CR1_CEN; // Enable TIM6 counter
}

void TIM6_DAC_IRQHandler() 
{ 
	if(TIM6->SR & TIM_SR_UIF != 0) // If update flag is set 
		GPIOD->BSRRL = (1 << 15); // Set D15 high 
	TIM6->SR &= ~TIM_SR_UIF; // Interrupt has been handled 
}


void init_timer4(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;	
	TIM4->PSC = 50000-1;
	TIM4->ARR = 4000-1;
	TIM4->CCR2 = 1000;
	TIM4->CCMR1 |= TIM_CCMR1_OC2M | TIM_CCMR1_OC2PE;  
	TIM4->CCER  |= TIM_CCER_CC2E;
	TIM4->DIER  |= TIM_DIER_UIE;
	TIM4->CR1   |= TIM_CR1_ARPE | TIM_CR1_CEN;
}


void init_timer4(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN; 
	GPIOD->MODER |= GPIO_MODER_MODER13_1;
	GPIOD->AFR[13] |= 2;
	TIM4->PSC =   5;
	TIM4->ARR =   100;
	TIM4->CCR2 =  50;
	TIM4->CCMR1 = TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;
	TIM4->CCER |= TIM_CCER_CC2E;
	TIM4->CR1 =   TIM_CR1_CEN;
}
*/
int main(void) {
	//RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIODRST;
	//RCC->AHB1RSTR = 0; 
	init_gpio();
	init_usart();

	while(1) 
	{
		USART1->DR = 0x61;
		GPIOA->BSRRH = (1 << 4);
		_wait(100000);
		GPIOA->BSRRL = (1 << 4);
		_wait(1000000);
	}
	return 0;
}
