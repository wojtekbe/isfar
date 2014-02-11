//#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
//#include <util/delay.h>

/*
 * LED -> PC0
 * SDA -> PC4
 * SCL -> PC5
 * RXD -> PD0
 * TXD -> PD1
 * SERVO -> OC2 (PB3)
 *
 * OCR2 = 6 - ?? limit
*/

#define LED_ON PORTC &= ~0x01
#define LED_OFF PORTC |= 0x01
#define LEDT PORC ^= 0x01

uint8_t pwm = 6; 
uint8_t buff[3] = {0xFF, 0xFF, 0xFF};
uint8_t idx = 0;

void init_IO(void) {	
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0x01;
	LED_OFF;
	PORTB = 0;
}


void init_PWM(void) {
	TCCR2 |= (1 << WGM20) | (1 << WGM21) |  //Fast PWM
		(1 << CS22) | // clk/64
		(1 << COM21); // Clear OC2 on Compare Match
	OCR2 = pwm;
	TIMSK |= _BV(TOIE2);
}

void init_UART(void) { // Baudrate = 2400
	UBRRH = 0x00;
	UBRRL = 0x19;	
	UCSRB = (1<<TXEN) | (1<<RXEN);
}

unsigned char us_read() {
	while ( !(UCSRA & (1<<RXC)) );
	return UDR;
}

void us_write(char c) {
	while ( !( UCSRA & (1<<UDRE)) );
	UDR = c;
}

void init_TWI(void) {
	TWAR = (0x0a << 1);
	TWCR |= _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE);
}


ISR(TIMER2_OVF_vect)
{
	OCR2 = pwm;
}


ISR(TWI_vect) 
{
	int i;

	// Slave receiver
	if(TWSR == 0x60) // SLA+W
	{
		TWCR |= (1 << TWEA);
		idx = 0;
		for(i=0; i<3; i++)
			buff[i] = 0xFF;
	}
	else if(TWSR == 0x80) // Got data 
	{
		buff[idx] = TWDR;
		idx++;
		TWCR |= (1 << TWEA);
	}
	else if(TWSR == 0xA0) // Got STOP
	{
		for(i=0; i<3; i++)
			us_write(buff[i]);
		pwm = buff[1];
	}
	else
	
	// Slave transmitter
	if(TWSR == 0xA8) // SLA+R
	{
		TWDR = 0x88;
		TWCR |= (1 << TWEA);
	}
	else if(TWSR == 0xB8) // Sent TWDR got ACK
	{

	}
	else if(TWSR == 0xC0) // Sent TWDR got NACK
	{
		us_write(0xFF);
	}
	else if(TWSR == 0xC8) // Last byte sent, got ACK
	{
		us_write(0xEE);
	}

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
	us_write(0xEF);
	while(1) 
	{
	}
	return 0;
}
