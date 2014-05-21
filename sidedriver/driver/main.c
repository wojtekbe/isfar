/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "debug.h"
#include "i2c.h"
#include "motordriver.h"
#include "pid.h"

void _wait(uint32_t);
int update_conf(void);

#define VECT_SIZE 5000
int32_t vect[VECT_SIZE];
int32_t vect2[VECT_SIZE];
int i;
int r;

void _wait(uint32_t nCount)
{
	while(nCount--)
		__asm__("NOP");
}

int update_conf(void)
{
	md_w_ref = (i2c_regs[M1_SET_SPEED] | (i2c_regs[M1_SET_SPEED + 1] << 8));
	//md_set_speed(pid.u);
	md_set_speed(md_w_ref); // with PID disabled
	return 0;
}

int main(void)
{
	debug_init(); /* on USART1 */
	i2c_init(); /* I2C1 */
	md_init();
	md_enable();

	pid.x = &md_w;
	pid.x_ref = &md_w_ref;
	pid_init();
	
	// debug("Hello\n");
	i = 0;
	r = 1;

	while(1)
	{
		//i2c_print_regs();
		update_conf();
		//debug("PID: x = %d, x_r = %d, u = %d\n", (int)*pid.x, (int)*pid.x_ref, pid.u);
		if (r)
			debug("%d	%d	%d	%d\n", i, (int32_t)TIM8->CNT, (int32_t)md_lpos, md_w);
		i++;

		/*
		if (r) {
			if (i < VECT_SIZE) {
				vect[i] = pid.u;
				vect2[i] = *pid.x;
				i++;
			}
			else {
				for (i = 0; i < VECT_SIZE; i++)
					debug("%d	%d	%d\n", i, vect[i], vect2[i]);
				r = 0;
			}
		}
		*/
		_wait(100000);
	}
}
