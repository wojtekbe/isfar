BIN=main.bin
ELF=main.elf

CC=arm-none-eabi-gcc
#LD=arm-none-eabi-gcc
#AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
#OD=arm-none-eabi-objdump

LIB=/home/wojtekbe/lib

STARTUP = $(LIB)/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f40xx.s

CFLAGS  = -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard 
CFLAGS += -mthumb-interwork -std=c99
CFLAGS += -I. -I$(LIB)/CMSIS/Device/ST/STM32F4xx/Include/ -I$(LIB)/CMSIS/Include/ 
CFLAGS += -DSTM32F4XX -DHSE_VALUE=8000000 
CFLAGS += -Wall -Wl,-T,stm32_flash.ld -g -Os
CFLAGS += -Wextra -Wimplicit-function-declaration -Wredundant-decls -Wmissing-prototypes
CFLAGS += -Wstrict-prototypes -Wundef -Wshadow
#CFLAGS += -I$(LIB)/STM32F4xx_StdPeriph_Driver/inc/
#CFLAGS += -DUSE_STDPERIPH_DRIVER

AFLAGS	= -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork 
#-mapcs-float use float regs. small increase in code size

SRC = debug.c i2c.c motordriver.c main.c system_stm32f4xx.c

all: $(BIN)

$(ELF): $(SRC) $(STARTUP)
	$(CC) $(CFLAGS) $^ -lm -lc -lnosys -o $@

$(BIN): $(ELF)
	$(CP) -O binary $^ $@

r: $(BIN)
	st-flash --reset write $^ 0x8000000
	

clean:
	rm -rf $(BIN) $(ELF)
