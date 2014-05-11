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

void _wait(uint32_t nCount)
{
	while(nCount--)
		__asm__("NOP");
}

int update_conf(void)
{
	md_w_ref = (i2c_regs[M1_SET_SPEED] | (i2c_regs[M1_SET_SPEED + 1] << 8));
	md_set_speed(pid.u);
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
	
	debug("Hello\n");
	while(1)
	{
		//i2c_print_regs();
		update_conf();
		debug("PID: x = %d, x_r = %d, u = %d\n", (int)*pid.x, (int)*pid.x_ref, pid.u);
		_wait(6000000);
	}
}
