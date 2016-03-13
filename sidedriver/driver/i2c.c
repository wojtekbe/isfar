/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include "debug.h"
#include "i2c.h"
#include "regs.h"

int i2c_reg_idx;
int i2c_bytes_received;

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

	debug("#i2c_init() OK\n");
}


void I2C1_EV_IRQHandler()
{
	uint16_t stat1 = 0;
	uint8_t data;
	uint16_t temp;

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
			regs[i2c_reg_idx] = data;
			i2c_reg_idx++;
		}
	}
	if(stat1 & I2C_SR1_TXE) // Transm. reg. empty
	{
		I2C1->DR = regs[i2c_reg_idx];
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

