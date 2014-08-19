/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "debug.h"
#include "time.h"
#include "i2c.h"
#include "motordriver.h"
#include "tankdriver.h"
#include "extio.h"

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
	// TODO store md_w
	//i2c_regs[M1_SPEED + 1] = (md_w >> 8) & 0x0FF;
	//i2c_regs[M1_SPEED] = md_w & 0x0FF;

	//md_set_speed(md_w_ref); // with PID disabled
	td_set_pos((i2c_regs[TANK_SET_POS] | (i2c_regs[TANK_SET_POS + 1] << 8)));
	// TODO store td_cpos
	return 0;
}

int main(void)
{

	debug_init(); /* on USART1 */
	debug("hello %d\n", SystemCoreClock);
	
	time_init();

	i2c_init(); /* I2C1 */
	
	td_init();
	td_enable();

	md_init();
	md_enable();

	extio_init();
	//r = 1;
	//i = 0;

	while(1)
	{
		//i2c_print_regs();
		update_conf();
		//debug("PID: x = %d, x_r = %d, u = %d\n", (int)*pid.x, (int)*pid.x_ref, pid.u);
		
		debug("%d: ADC3 = %d g\n", time_ms, extio_adc1_read()/4);

		//if (r) {
		//	debug("%d\t%d\t%d\t%d\n", i, md_w, md_w_ref, pid.u);
		// debug("%d	%d	%d	%d\n", i, (int32_t)TIM8->CNT, (int32_t)md_lpos, md_w);
		// i++;
		_wait(10000000);
	}
}
