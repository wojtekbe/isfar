/* wojtekbe@gmail.com */

#include <libopencm3/stm32/f4/rcc.h>
#include <libopencm3/stm32/f4/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/timer.h>

static void clock_setup(void)
{
	rcc_peripheral_enable_clock(&RCC_AHB1ENR, RCC_AHB1ENR_IOPAEN);
	rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_USART1EN);
}

static void usart_setup(void)
{
	usart_set_baudrate(USART1, 115200);
	usart_set_databits(USART1, 8);
	usart_set_stopbits(USART1, USART_STOPBITS_1);
	usart_set_mode(USART1, USART_MODE_TX_RX);
	usart_set_parity(USART1, USART_PARITY_NONE);
	usart_set_flow_control(USART1, USART_FLOWCONTROL_NONE);
	usart_enable(USART1);
}

static void gpio_setup(void)
{
	// temporary LED PA4
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO4);

	// USART1 TX pin (PA9) clock
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO9);
	gpio_set_af(GPIOA, GPIO_AF7, GPIO9);
}

void _wait(int c)
{
	int i;
	for (i = 0; i < c; i++) 
		__asm__("nop");
}

void usart_send_uint32(uint32_t i)
{
	usart_send_blocking(USART1, (uint8_t)((i >> 24) & 0x000000FF));
	usart_send_blocking(USART1, (uint8_t)((i >> 16) & 0x000000FF));
	usart_send_blocking(USART1, (uint8_t)((i >> 8) & 0x000000FF));
	usart_send_blocking(USART1, (uint8_t)(i & 0x000000FF));
}

int main(void)
{
	clock_setup();
	gpio_setup();
	usart_setup();
	while (1) 
	{
		usart_send_uint32(USART1_CR1);
		gpio_toggle(GPIOA, GPIO4);
		_wait(1000000);
	}
	return 0;
}
