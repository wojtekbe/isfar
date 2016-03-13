#ifndef _regs_h_
#define _regs_h_

#include "debug.h"

#define NUM_REGS 8

/* Reg. addresses */
#define STATE 			0x00 /* TODO */
#define M_SET_SPEED 	0x02 /* motor set speed */
#define M_SPEED 		0x04 /* current motor speed */
#define TANK_SET_POS 	0x06 /* tank set position */
#define TANK_POS 		0x08 /* current tank position */
#define PID_KP 			0x0A /* Kp param of PID motor controller */
#define PID_KI 			0x0C /* Ki param of PID motor controller */
#define PID_KD 			0x0E /* Kd param of PID motor controller */

uint8_t regs[NUM_REGS * sizeof(uint16_t)];

inline void regs_print(void)
{
	uint16_t i;
	debug("[ ");
	for(i = 0; i < (NUM_REGS * sizeof(uint16_t)); i++)
		debug("%02x ", regs[i]);
	debug("]\n");
}

#endif
