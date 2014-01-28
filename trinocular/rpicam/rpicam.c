#define F_CPU 1000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define LED_ON PORTC &= ~0x01
#define LED_OFF PORTC |= 0x01
#define BLINK LED_ON; _delay_ms(100); LED_OFF
char pwm = 10;

void init_IO(void) {	
	DDRB = 0xFF;
	DDRD = 0xFF;
	DDRC = 0x01;
	LED_OFF;
}

void init_PWM(void) {
	TCCR2 |= _BV(WGM20) | _BV(WGM21) | _BV(CS22) | _BV(COM21);
	OCR2 = pwm;
	TIMSK |= _BV(TOIE2);
}

void init_TWI(void) {
	TWAR = 0x04;
	TWCR |= _BV(TWINT) | _BV(TWEA) | _BV(TWEN) | _BV(TWIE);
	BLINK;

}

ISR(TIMER2_OVF_vect)
{
	OCR2 = pwm;
}

ISR(TWI_vect) 
{
	BLINK;
	switch(TWSR) 
	{
		case 0x60: 
			break;
		case 0x80: 
			pwm = TWDR;
			break;
		case 0xA0:
			break;
		case 0xA8:
			TWDR = 0x80;
			break;
		case 0xB8:
			break;
	}
}

int main (void)
{
	init_IO();
	init_PWM();
	init_TWI();
	sei();
	while(1);	
	return 0;
}
