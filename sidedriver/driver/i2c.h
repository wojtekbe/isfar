#ifndef _i2c_h_
#define _i2c_h_

#define I2C_ADDR 0x09

void i2c_init(void);
void I2C1_EV_IRQHandler(void);
void I2C1_ER_IRQHandler(void);

#endif
