/* wojtekbe@gmaill.com */
#include "stm32f4xx.h"
#include "core_cm4.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "debug.h"
#include "i2c.h"
#include "motordriver.h"

void _wait(uint32_t);
int update_conf(void);

void _wait(uint32_t nCount)
{
	while(nCount--)
		__asm__("NOP");
}

int update_conf(void)
{
	md_w_ref = i2c_regs[M1_SET_SPEED] | (i2c_regs[M1_SET_SPEED + 1] << 8);
	return 0;
}

int main(void)
{
	debug_init(); /* on USART1 */
	i2c_init(); /* I2C1 */
	md_init();
	md_enable();
	debug("Hello\n");
	while(1)
	{
		//i2c_print_regs();
		update_conf();
		debug("Tp=%d, e=%d, u=%d, w_r=%d, w=%d \n", pid.Tp, pid.e, pid.u, md_w_ref, md_w);
		//debug("md_cpos=%d, w=%d, CCMR1=0x%04x\n", md_cpos, md_w, TIM8->CCMR1);
		_wait(6000000);
	}
}
