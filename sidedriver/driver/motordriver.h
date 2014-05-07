#ifndef _motordriver_h_
#define _motordriver_h_

#define M1_MAX_SPEED 3370
#define PID_MAX_U 1500

void md_init(void);
void md_enable(void);
void md_disable(void);
//void md_dir(uint8_t);
void md_pwm(uint32_t);
void md_set_speed(int16_t);

void TIM4_IRQHandler(void);
void TIM5_IRQHandler(void);

uint16_t md_cpos;
uint16_t md_lpos;
int16_t md_w;
int16_t md_w_ref;
int32_t md_enc_upd_ms;

struct PID {
	int enabled;
	int32_t Kp;
	int32_t Kd;
	int32_t Ki;
	int32_t Tp;
	int32_t e;
	int32_t u;
	int32_t sum_of_e;
	int32_t last_e;
} pid;

#endif
