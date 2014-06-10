#ifndef _motordriver_h_
#define _motordriver_h_

void md_init(void);
void md_enable(void);
void md_disable(void);
void md_set_speed(int16_t);

struct PID {
	int enabled;
	int16_t u; 
	int16_t *x;
	int16_t *x_ref;

	int32_t Kp;
	int32_t Kd;
	int32_t Ki;
	int32_t Tp;
	int32_t e;
	int32_t sum_of_e;
	int32_t last_e;
} pid;

int16_t md_w;
int16_t md_w_ref;
uint16_t md_cpos;
uint16_t md_lpos;

#endif
