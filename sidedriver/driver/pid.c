/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include <math.h>
#include "debug.h"
#include "pid.h"

void pid_init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	TIM5->PSC = 8400 - 1;
	TIM5->ARR = 2000 - 1;
	TIM5->DIER = TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM5_IRQn);
	TIM5->CR1 |= TIM_CR1_CEN; // PID start

	pid.Kp = 1;
	pid.Kd = 0;
	pid.Ki = 1000;
	pid.Tp = (((TIM5->PSC+1)*(TIM5->ARR+1)) / 84000); // in ms
	pid.last_e = 0;
	pid.sum_of_e = 0;
	pid.enabled = 1;

	debug("pid_init OK\n");
}

void TIM5_IRQHandler(void) /* PID IRQ */
{
	if(TIM5->SR & TIM_SR_UIF) {
		/* If U don't want PID */
		/*pid.u = *pid_x_ref;*/
		pid.e = *pid.x_ref - *pid.x;
		pid.sum_of_e += pid.e;
		pid.u = pid.Kp * (pid.e + /* prop. */
				(pid.Tp * pid.sum_of_e / pid.Ki) +  /* integr. */
				(pid.Kd * (pid.e - pid.last_e) / pid.Tp)); /* diff. */

		/* limit u */
		if (pid.u > PID_MAX_U)
			pid.u = PID_MAX_U;
		if (pid.u < -PID_MAX_U)
			pid.u = -PID_MAX_U;

		pid.last_e = pid.e;
		//md_set_speed(pid.u);
	}
	TIM5->SR &= ~TIM_SR_UIF;

}
