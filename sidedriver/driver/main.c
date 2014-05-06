/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define DEBUG

#ifdef DEBUG
#define debug(...) printf(__VA_ARGS__);
#else
#define debug(...) do { } while(0)
#endif

// prototypes
void _wait(uint32_t);

void usart_init(void);
int _write(int, char*, int);
void usart_send(uint8_t);

void init_ledd(void);

void i2c_init(void);
void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);
#define I2C_ADDR 0x09
#define NUM_REGS 4
#define STATE 0x00
#define M1_SET_SPEED_L 0x01
#define M1_SET_SPEED_H 0x02
#define M1_SPEED_L 0x03
#define M1_SPEED_H 0x04
int16_t i2c_regs[NUM_REGS];
int i2c_bytes_received;
int i2c_reg_idx;

#define M1_MAX_SPEED 3370
#define PID_MAX_U 1500
void md_init(void);
void md_enable(void);
void md_disable(void);
void md_dir(uint8_t);
void md_pwm(uint32_t);
void md_set_speed(int16_t);
void TIM4_IRQHandler(void);
uint16_t md_cpos = 0;
uint16_t md_lpos = 0;
int16_t md_w = 0;
int16_t md_w_ref;
int32_t md_enc_upd_ms;
/*
   int32_t md_pid_Tp;
   const int32_t md_pid_kp = 2;
   const int32_t md_pid_Ti = 3000;
   const int32_t md_pid_Td = 0;
   int32_t md_pid_e;
   int32_t md_pid_u;
   int32_t md_pid_sum_of_e;
   int32_t md_pid_last_e;
   */

struct PID {
	int enabled;
	int32_t Kp;
	int32_t Kd;
	int32_t Ki;
	int32_t Tp;
	int32_t e;
	int32_t u;
	int32_t sum_of_e;
	int32_t last_e;
} pid;

void td_init(void);
void td_enable(void);
void td_disable(void);
void td_dir(uint8_t);
void td_pwm(int);
void EXTI15_10_IRQHandler(void);


int update_conf(void);

void _wait(uint32_t nCount)
{
	while(nCount--)
		__asm__("NOP");
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

void usart_init(void)
{
	/*
	 * TX 	PA9 	USART1_TX
	 * RX 	PA10 	USART1_RX
	 */
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER9_1;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR9_0;
	GPIOA->AFR[1] |= (7 << 4);
	USART1->BRR = 0x2D9; // 115200
	USART1->CR3 |= USART_CR3_ONEBIT; // Doesn't work without that...
	USART1->CR1 |= USART_CR1_TE | USART_CR1_UE;
}

void usart_send(uint8_t d)
{
	while ((USART1->SR & USART_SR_TXE) == 0);
	USART1->DR = d;
}

void i2c_init(void)
{
	/*
	 * SDA	PB9		I2C1_SDA
	 * SCL	PB8		I2C1_SCL
	 */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
	GPIOB->OTYPER |= (1 << 8) | (1 << 9); // Open drain PB7,8
	GPIOB->PUPDR |= GPIO_PUPDR_PUPDR8_0 | GPIO_PUPDR_PUPDR9_0; // Enable Pull-Ups for PB7,8
	GPIOB->MODER |= GPIO_MODER_MODER8_1 | GPIO_MODER_MODER9_1; // AF
	GPIOB->AFR[1] |= (4 << 4); // AF4 for PB9 SDA
	GPIOB->AFR[1] |= (4 << 0); // AF4 for PB8 SCL
	I2C1->OAR1 = (I2C_ADDR << 1) | (1 << 14);
	NVIC_EnableIRQ(I2C1_EV_IRQn);
	NVIC_EnableIRQ(I2C1_ER_IRQn);
	I2C1->CR2 |= I2C_CR2_ITERREN | I2C_CR2_ITEVTEN | I2C_CR2_ITBUFEN;
	I2C1->CR1 |= I2C_CR1_ACK | I2C_CR1_PE;

	i2c_reg_idx = 0;
	i2c_bytes_received = 0;

	//debug("i2c_init()\n");
}

void i2c_print_regs(void)
{
	int i;
	printf("[ ");
	for(i=0; i<=NUM_REGS; i++)
		printf("0x%02x ", i2c_regs[i]);
	printf("]\n");
}

void I2C1_EV_IRQHandler()
{
	uint16_t temp;
	uint16_t stat1 = 0;
	uint8_t data;

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
		{
			i2c_regs[i2c_reg_idx] = data;
			i2c_reg_idx++;
		}
	}
	if(stat1 & I2C_SR1_TXE) // Transm. reg. empty
	{
		I2C1->DR = i2c_regs[i2c_reg_idx];
		i2c_reg_idx++;
	}
	if(stat1 & I2C_SR1_BTF) // Byte Transfer Finished
	{
		// nothing? really?
	}
	if(stat1 & I2C_SR1_STOPF) // STOP received, EV4
	{
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

	if(stat1 & I2C_SR1_AF) // ACK failure (NACK)
	{
		I2C1->SR1 &= ~I2C_SR1_AF;
	}
	if(stat1 & I2C_SR1_OVR) // Overflow
	{
		I2C1->SR1 &= ~I2C_SR1_OVR;
	}
}

void md_init(void)
{
	/*
	 * M1-PWM 	PA1 	TIM2_CH2
	 * M1-CS 	PA2 	ADC123_IN2
	 * M1-ENB 	PA3 	out
	 * M1-INB 	PA4 	out
	 * M1-INA 	PC2 	out
	 * M1-ENA 	PC3 	out
	 * ENC1 	PC6 	TIM8_CH1
	 * ENC2 	PC7 	TIM8_CH2
	 */
	//debug("md_init()\n");

	// IOs
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER3_0; // M1-ENB
	GPIOA->MODER |= GPIO_MODER_MODER4_0; // M1-INB
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	GPIOC->MODER |= GPIO_MODER_MODER2_0; // M1-INA
	GPIOC->MODER |= GPIO_MODER_MODER3_0; // M1-ENA

	// PWM: TIM2_CH2 (PA1/AF1)
	GPIOA->MODER |= GPIO_MODER_MODER1_1; // AF
	GPIOA->AFR[0] |= (1 << 4); // AF1
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC =   83;
	TIM2->ARR =   99; // 10 kHz
	TIM2->CCMR1 = TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1;
	TIM2->CCER = TIM_CCER_CC2E;

	// Encoder: counting tics: TIM8_CH1/2 (PC6/7 AF3)
	GPIOC->MODER |= GPIO_MODER_MODER6_1; // PC6 -> AF
	GPIOC->AFR[0] |= (3 << 24); // PC6 -> AF3
	GPIOC->MODER |= GPIO_MODER_MODER7_1; // PC7 -> AF
	GPIOC->AFR[0] |= (3 << 28); // PC7 -> AF3
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
	TIM8->ARR = 0xFFFF;
	TIM8->PSC = 2 - 1; // (Prescaler - 1)
	TIM8->CCMR1 = TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0; // CC1S = 01, CC2S = 02 (inputs)
	TIM8->CCER |= TIM_CCER_CC1P | TIM_CCER_CC2P; // CC1P = 1, CC2P = 1 input polarity
	TIM8->SMCR |= TIM_SMCR_SMS_1 | TIM_SMCR_SMS_0; // Slave Mode, SMS = 011, Encoder Mode 3 p. 615
	TIM8->EGR |= TIM_EGR_UG; /* Force update */
	TIM8->CR1 |= TIM_CR1_CEN;

	//Calculate speed using TIM4 interrupt
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	TIM4->PSC = 8400 - 1;
	TIM4->ARR = 200 - 1;
	TIM4->DIER = TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM4_IRQn);
	TIM4->EGR |= TIM_EGR_UG; /* Force update */
	TIM4->CR1 |= TIM_CR1_CEN;
	md_enc_upd_ms = ( ((TIM4->PSC+1)*(TIM4->ARR+1)) / 84000 );

	// TODO Current measure: M1-CS
	GPIOA->MODER |= GPIO_MODER_MODER2_0 | GPIO_MODER_MODER2_1;
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	//ADC->CR1 |=
	//ADC->CR2 |= ADC_CR2_ADON;

	// TODO: PID controller on TIM5
	pid.enabled = 1;
	if (pid.enabled) {
		RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
		TIM5->PSC = 8400 - 1;
		TIM5->ARR = 2000 - 1;
		TIM5->DIER = TIM_DIER_UIE;
		NVIC_EnableIRQ(TIM5_IRQn);
		TIM5->CR1 |= TIM_CR1_CEN; // PID start

		pid.Kp = 1;
		pid.Kd = 0;
		pid.Ki = 10000;
		pid.Tp = (((TIM5->PSC+1)*(TIM5->ARR+1)) / 84000); // in ms
		pid.last_e = 0;
		pid.sum_of_e = 0;
	}

	debug("md_init OK\n");
}

void TIM4_IRQHandler(void)  // md: Calculate rotating speed
{
	if(TIM4->SR & TIM_SR_UIF)
	{
		md_cpos = TIM8->CNT;
		md_w = ((int16_t)md_cpos - (int16_t)md_lpos) * 30 / 4; // [RPM]
		//md_w = md_w_ref;
		md_lpos = md_cpos;
		i2c_regs[M1_SPEED_H] = (md_w >> 8) & 0x0FF;
		i2c_regs[M1_SPEED_L] = md_w & 0x0FF;
	}
	TIM4->SR &= ~TIM_SR_UIF;
}

void TIM5_IRQHandler(void) /* PID IRQ */
{
	if(TIM5->SR & TIM_SR_UIF) {
		pid.e = md_w_ref - md_w;
		pid.sum_of_e += pid.e;
		pid.u = pid.Kp * (pid.e + /* prop. */
				(pid.Tp * pid.sum_of_e / pid.Ki) +  /* integr. */
				(pid.Kd * (pid.e - pid.last_e) / pid.Tp)); /* diff. */

		// md_pid_u = md_w_ref + md_pid_u;
		/* limit u */
		if (pid.u > PID_MAX_U)
			pid.u = PID_MAX_U;
		if (pid.u < -PID_MAX_U)
			pid.u = -PID_MAX_U;

		pid.last_e = pid.e;
		md_set_speed(pid.u);
		// printf("w_ref=%d, w=%d, e=%d, u=%d\n", md_w_ref, md_w, md_pid_e, md_pid_u);
	}
	TIM5->SR &= ~TIM_SR_UIF;

}

void md_dir(uint8_t dir)
{
	//debug("md_dir(%d)\n", dir);

	if(dir < 0x80)
	{
		GPIOC->ODR |=  (1 << 2); // M1-INA = 1
		GPIOA->ODR &= ~(1 << 4); // M1-INB = 0
	}
	else
	{
		GPIOC->ODR &= ~(1 << 2); // M1-INA = 0
		GPIOA->ODR |=  (1 << 4); // M1-INB = 1
	}
}

void md_pwm(uint32_t width)
{
	//debug("md_pwm(%d)\n", PWM);

	if (width != TIM2->CCR2) {
		if (width == 0)
			TIM2->CR1 &= ~TIM_CR1_CEN;
		else
			TIM2->CR1 |= TIM_CR1_CEN;

		TIM2->CCR2 = width;
	}
}

void md_set_speed(int16_t w)
{
	uint16_t pwm;
	if (w > M1_MAX_SPEED)
		w = M1_MAX_SPEED;

	if (w < -M1_MAX_SPEED)
		w = -M1_MAX_SPEED;

	pwm = (abs(w) * (TIM2->ARR + 1) / M1_MAX_SPEED);
	//printf("w=%d, pwm=%d\n", w, pwm);

	if (w == 0) {
		TIM2->CR1 &= ~TIM_CR1_CEN; // stop counting/pwm
		TIM2->CCR2 = 0;
	} else if (w > 0) {
		TIM2->CCR2 = pwm;
		TIM2->CR1 |= TIM_CR1_CEN; // pwm start
		GPIOC->ODR |=  (1 << 2); // M1-INA = 1
		GPIOA->ODR &= ~(1 << 4); // M1-INB = 0
	} else {
		TIM2->CCR2 = pwm;
		TIM2->CR1 |= TIM_CR1_CEN; // pwm start
		GPIOC->ODR &= ~(1 << 2); // M1-INA = 0
		GPIOA->ODR |=  (1 << 4); // M1-INB = 1
	}
}

void md_enable()
{
	debug("md_enable()\n");

	GPIOC->ODR |= (1 << 3); // M1-ENA = 1
	GPIOA->ODR |= (1 << 3); // M1-ENB = 1
}

void md_disable()
{
	debug("md_disable()\n");

	GPIOC->ODR &= ~(1 << 3); // M1-ENA = 0
	GPIOA->ODR &= ~(1 << 3); // M1-ENB = 0
}

void td_init()
{
	/*
	 * M2-PWM 	PB0 	TIM1_CH2N
	 * M2-ENA 	PB1 	out
	 * M2-INA 	PB2 	out
	 * MIN		PB10	in
	 * MAX		PB11	in
	 * M2-ENB 	PA6 	out
	 * M2-INB 	PA5 	out
	 * TRANS 	PC8 	TIM3_CH3
	 */

	//debug("td_init()\n");

	// IOs
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODER1_0; // M2-ENA
	GPIOB->MODER |= GPIO_MODER_MODER2_0; // M2-INA

	// TODO MIN MAX
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG->EXTICR[2] |= (1 << 12);  // MAX
	//SYSCFG->EXTICR[2] |= (1 << 8); // PB10
	EXTI->IMR |= (1 << 11); // Interrupt Mask Reg.
	EXTI->FTSR |= (1 << 11); // MAX Falling Trigger
	//NVIC_EnableIRQ(EXTI15_10_IRQn);

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER6_0; // M2-ENB
	GPIOA->MODER |= GPIO_MODER_MODER5_0; // M2-INB


	// PWM: TIM1_CH2N (PB0/AF1)
	GPIOB->MODER |= GPIO_MODER_MODER0_1; // AF
	GPIOB->AFR[0] |= (1 << 0); // AF1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	TIM1->PSC =   10 - 1;
	TIM1->ARR =   100 - 1;
	TIM1->BDTR |= TIM_BDTR_MOE;
	TIM1->CCMR1 = TIM_CCMR1_OC2M_2 | TIM_CCMR1_OC2M_1; // PWM mode for CH2
	TIM1->CCER = TIM_CCER_CC2NE;

	// TRANS ?
	//RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	//GPIOC->MODER |= GPIO_MODER_MODER8_1;
}

void EXTI15_10_IRQHandler()  // td: MIN or MAX interrupt
{
	EXTI->PR = EXTI_PR_PR11;
	printf("EXTI\n");
}

void td_pwm(int width)
{
	if(width != TIM1->CCR2)
	{
		if(width == 0)
			TIM1->CR1 &= ~TIM_CR1_CEN;
		else
			TIM1->CR1 |= TIM_CR1_CEN;

		TIM1->CCR2 = width;
	}
}

void td_enable()
{
	//debug("td_enable()\n");
	GPIOB->ODR |= (1 << 1); // M2-ENA = 1
	GPIOA->ODR |= (1 << 6); // M2-ENB = 1
}

void td_disable()
{
	//debug("td_disable()\n");
	GPIOB->ODR &= ~(1 << 1); // M2-ENA = 0
	GPIOA->ODR &= ~(1 << 6); // M2-ENB = 0
}

void td_dir(uint8_t d)
{
	//debug("td_dir(%d)\n", d);

	if(d < 0x80) // water out
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

int update_conf(void)
{
	//int r = 0;
	md_w_ref = i2c_regs[M1_SET_SPEED_L] | (i2c_regs[M1_SET_SPEED_H] << 8);
	//md_set_speed(md_w_ref);
	// printf("md_w_ref = %d, md_w = %d\n ", md_w_ref, md_w);

	/*
	   while(r<NUM_REGS)
	   {
	   r++;
	   }
	   */
	return 0;
}

int main(void)
{
	usart_init();
	i2c_init();
	md_init();
	md_enable();
	//td_init();
	//td_enable();
	//init_ledd();
	printf("Hello\n");
	while(1)
	{
		update_conf();
		printf("Tp=%d, e=%d, u=%d, w_r=%d, w=%d \n", pid.Tp, pid.e, pid.u, md_w_ref, md_w);
		//printf("md_cpos=%d, w=%d, CCMR1=0x%04x\n", md_cpos, md_w, TIM8->CCMR1);
		//i2c_print_regs();
		_wait(6000000);
	}
}
