#ifndef _motordriver_h_
#define _motordriver_h_


void md_init(void);
void md_enable(void);
void md_disable(void);
void md_set_speed(int16_t);

int16_t md_w;
int16_t md_w_ref;
uint16_t md_cpos;
uint16_t md_lpos;

#endif
