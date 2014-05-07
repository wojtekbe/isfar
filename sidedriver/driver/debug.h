#ifndef _debug_h_
#define _debug_h_

#define DEBUG

#ifdef DEBUG
#define debug(...) printf(__VA_ARGS__);
#else
#define debug(...) do { } while(0)
#endif

void debug_init(void);
int _write(int, char*, int);
void usart_send(uint8_t);

#endif
