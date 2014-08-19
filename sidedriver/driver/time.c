#include "stm32f4xx.h"
#include "time.h"
#include "core_cm4.h"

void SysTick_Handler(void)
{
	time_ms++;
}

void time_init(void)
{
	time_ms = 0;
	SysTick_Config(SystemCoreClock/1000);
}
