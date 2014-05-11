#ifndef _motordriver_h_
#define _motordriver_h_

#define M1_MAX_SPEED 3370

void md_init(void);
void md_enable(void);
void md_disable(void);
//void md_dir(uint8_t);
//void md_pwm(uint32_t);
void md_set_speed(int16_t);

void TIM4_IRQHandler(void);

int16_t md_w;
int16_t md_w_ref;
int32_t md_enc_upd_ms;
uint16_t md_cpos;
uint16_t md_lpos;

#endif
