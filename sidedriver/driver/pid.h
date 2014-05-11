#ifndef _pid_h_
#define _pid_h_

#define PID_MAX_U 1500
void pid_init(void);
void TIM5_IRQHandler(void);

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

#endif
