#ifndef _debug_h_
#define _debug_h_

#include <stdio.h>

#define DEBUG
#define LED(x) ((x) ? (GPIOA->ODR &= ~(1 << 12)) : (GPIOA->ODR |= (1 << 12)))
#define LEDT(x) (((GPIOA->ODR & (1 << 12))) ? LED(1) : LED(0));

#ifdef DEBUG
#define debug(...) printf(__VA_ARGS__);
#else
#define debug(...) do { } while(0)
#endif

void debug_init(void);
int _write(int, char*, int);
void usart_send(uint8_t);

#endif
