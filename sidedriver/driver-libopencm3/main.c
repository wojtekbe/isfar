/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2011 Stephen Caudle <scaudle@doceme.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>


void usart_send_uint32(uint32_t);

static void clock_setup(void)
{
	/* Enable GPIOD clock for LED & USARTs. */
	//rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPDEN);
	RCC_AHB1ENR |= RCC_AHB1ENR_IOPDEN;
	//rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPAEN);
	RCC_AHB1ENR |= RCC_AHB1ENR_IOPAEN;
	
	/* Enable clocks for USART2. */
	//rcc_peripheral_enable_clock(&RCC_APB1ENR, RCC_APB1ENR_USART2EN);
	RCC_APB1ENR |= RCC_APB1ENR_USART2EN;
}

static void usart_setup(void)
{
	//usart_set_baudrate(USART2, 115200);
	USART2_BRR = 0x8B;
	//usart_set_mode(USART2, USART_MODE_TX);
	USART2_CR1 |= USART_CR1_TE;
	//usart_enable(USART2);
	USART2_CR1 |= USART_CR1_UE;
}

static void gpio_setup(void)
{
	gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12);
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO2);
	gpio_set_af(GPIOA, GPIO_AF7, GPIO2);
}

void usart_send_uint32(uint32_t i)
{
	usart_send_blocking(USART2, (uint8_t)((i >> 24) & 0x000000FF));
	usart_send_blocking(USART2, (uint8_t)((i >> 16) & 0x000000FF));
	usart_send_blocking(USART2, (uint8_t)((i >> 8) & 0x000000FF));
	usart_send_blocking(USART2, (uint8_t)(i & 0x000000FF));
}

int main(void)
{
	int i;

	clock_setup();
	gpio_setup();
	usart_setup();

	while (1) {
		gpio_toggle(GPIOD, GPIO12);	/* LED on/off */
		usart_send_uint32(USART2_BRR);
		usart_send_blocking(USART2, 0xff);
		usart_send_uint32(rcc_ppre2_frequency);
		usart_send_blocking(USART2, 0xff);
		for (i = 0; i < 3000000; i++)	/* Wait a bit. */
			__asm__("NOP");
	}
	return 0;
}
