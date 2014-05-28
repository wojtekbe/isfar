#ifndef _tankdriver_h_
#define _tankdriver_h_

#define WATER_IN 1
#define WATER_OUT -1
#define MIN ((GPIOB->IDR & (1 << 10)) ? 1 : 0)

void td_init(void);
void td_enable(void);
void td_disable(void);
void td_set_dir(int32_t);

int32_t td_cpos;
int32_t td_pos;

int8_t td_dir;
#endif
