#ifndef _i2c_h_
#define _i2c_h_

#define I2C_ADDR 0x09
#define NUM_REGS 4

/* Reg. addresses */
#define STATE 0x00
#define M1_SET_SPEED 0x02 /* RW */
#define M1_SPEED 0x04 /* R */
#define TANK_SET_POS 0x06 /* RW */
#define TANK_POS 0x08 /* R */

void i2c_init(void);
void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);
void i2c_print_regs(void);

uint8_t i2c_regs[NUM_REGS * sizeof(uint16_t)];
int i2c_bytes_received;
int i2c_reg_idx;

#endif
