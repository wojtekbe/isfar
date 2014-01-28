PROJ=sidedriver

# http://www.farrellf.com/projects/hardware/2012-06-09_First_Steps_with_the_STM32F4_in_Linux_%28Part_2%29/
#uses git://github.com/karlp/kkstm32_base
LIB=/home/wojtekbe/lib/STM32F4xx_StdPeriph_Driver

CC=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy

CFLAGS=-g -O2 -mlittle-endian -mthumb
CFLAGS+=-mcpu=cortex-m4 -mhard-float -mfpu=vfp
CFLAGS+=-ffreestanding 
CFLAGS+=-nostdlib

# to run from FLASH
CFLAGS+=-Wl,-T,stm32_flash.ld

# stm32f4xx_stdperiph_driver
CFLAGS+=-I$(LIB)/inc
CFLAGS+=-I$(LIB)/inc/device_support
CFLAGS+=-I$(LIB)/inc/core_support

LDFLAGS+= 

all: $(PROJ).bin

$(PROJ).bin: $(PROJ).elf
	$(OBJCOPY) -O binary $^ $@


$(PROJ).elf: main.c system_stm32f4xx.c startup_stm32f4xx.s
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@  
	
r: $(PROJ).bin
	st-flash --reset write $(PROJ).bin 0x08000000

clean:
	rm -rf *.o
	rm -rf $(PROJ).elf $(PROJ).bin

.PHONY: all clean
