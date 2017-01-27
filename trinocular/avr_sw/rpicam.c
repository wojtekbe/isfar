//#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>

/*
 * LED -> PC0
 * SDA -> PC4
 * SCL -> PC5
 * RXD -> PD0
 * TXD -> PD1
 * SERVO -> OC2 (PB3)
 * PB1 -> Power-LED 1 ctrl
 * PB2 -> Power-LED 2 ctrl
 *
 * OCR2 = 6 - ?? limit
 *
 * Register map:
 * 0x00 status (TODO)
 * 0x01 servo PWM val (in cycles)
 * 0x02 Power-LED 1 (cycles)
 * 0x03 Power-LED 2 (cycles)
*/

#define LED_ON PORTC &= ~0x01
#define LED_OFF PORTC |= 0x01
#define LEDT PORTC ^= 0x01

#define ADDR 0x0A
#define NUM_REGS 4
#define REG_STATUS 0
#define REG_SERVO 1
#define REG_LED1 2
#define REG_LED2 3

uint8_t regs[NUM_REGS] = {0x00, 0x14, 0x80, 0x80};
uint8_t twi_buff[3] = {0xFF, 0xFF, 0xFF};
uint8_t idx = 0;

/* Input/Output */
void init_IO(void)
{
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0x01;
	PORTB = 0;
	LED_OFF;
}

/* Timers */
void init_PWM(void)
{
	/* init Timer/Counter1 - powerleds */
	TCCR1A |= _BV(COM1A1) | _BV(COM1B1) | _BV(WGM10);
	TCCR1B |= _BV(WGM12) | _BV(CS10);
	OCR1A = regs[REG_LED1];
	OCR1B = regs[REG_LED2];
	TIMSK |= _BV(TOIE1);

	/* init Timer/Counter2 - servo */
	TCCR2 |= (1 << WGM20) | (1 << WGM21) | (1 << CS22) | (1 << COM21);
	OCR2 = regs[REG_SERVO];
	TIMSK |= _BV(TOIE2);
}

ISR(TIMER1_OVF_vect)
{
	OCR1A = regs[REG_LED1];
	OCR1B = regs[REG_LED2];
}

ISR(TIMER2_OVF_vect)
{
	OCR2 = regs[REG_SERVO];
}

/* UART */
void init_UART(void)
{
	/* Baudrate = 2400 */
	UBRRH = 0x00;
	UBRRL = 0x19;
	UCSRB = (1<<TXEN) | (1<<RXEN);
}

unsigned char us_read()
{
	while (!(UCSRA & (1<<RXC)));
	return UDR;
}

void us_write(char c)
{
	while (!( UCSRA & (1<<UDRE)));
	UDR = c;
}

/* Two-wire interface (I2C) */
void init_TWI(void)
{
	TWAR = (ADDR << 1);
	TWCR |= _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE);
}

ISR(TWI_vect)
{
	int i;

	if(TWSR == 0x60) { /* on Write */
		TWCR |= (1 << TWEA);
		idx = 0;
		for(i=0; i<3; i++)
			twi_buff[i] = 0xFF;
	}
	else if(TWSR == 0x80) { /* received a byte */
		twi_buff[idx] = TWDR;
		idx++;
		TWCR |= (1 << TWEA);
	}
	else if(TWSR == 0xA0) { /* on Stop */
		if (twi_buff[0] >= 0 && twi_buff[0] < NUM_REGS) {
			regs[twi_buff[0]] = twi_buff[1];
		}
		/* TODO: else return NACK */
	}
	else if(TWSR == 0xA8) { /* on Read */
		TWDR = 0x00; /* transmit 0x00 */
		TWCR |= (1 << TWEA);
	}
	else if(TWSR == 0xB8) {}
	else if(TWSR == 0xC0) {}
	else if(TWSR == 0xC8) {}

	TWCR |= (1 << TWINT);
}

int main (void)
{
	init_IO();
	init_UART();
	init_PWM();
	init_TWI();
	sei();
	LED_ON;
	us_write(0xEF); /* wite Hello */

	while(1);

	return 0;
}
