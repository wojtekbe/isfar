BIN=main.bin
ELF=main.elf

CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump

LIB=/home/wojtekbe/lib

CFLAGS = -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork -std=c99
CFLAGS += -I$(LIB)/CMSIS/Device/ST/STM32F4xx/Include/ \
		 -I$(LIB)/CMSIS/Include/ -I$(LIB)/STM32F4xx_StdPeriph_Driver/inc/ \
		 -I.
CFLAGS += -DUSE_STDPERIPH_DRIVER -DSTM32F4XX -DHSE_VALUE=8000000 
CFLAGS += -Wall -Wl,-T,stm32_flash.ld -g -Os \
		  -Wextra -Wimplicit-function-declaration -Wredundant-decls -Wmissing-prototypes \
		  -Wstrict-prototypes -Wundef -Wshadow
CFLAGS += -DTINYPRINTF_DEFINE_TFP_PRINTF=1 \
		  -DTINYPRINTF_DEFINE_TFP_SPRINTF=1 \
		  -DTINYPRINTF_OVERRIDE_LIBC=1 \

AFLAGS	= -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork 

STARTUP = $(LIB)/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f40xx.s
SRC = main.c \
	stm32f4xx_it.c \
	system_stm32f4xx.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c \
	tinyprintf.c

all: $(BIN)

$(ELF): $(SRC) $(STARTUP)
	$(CC) $(CFLAGS) $^ -lm -lc -lnosys -o $@

$(BIN): $(ELF)
	$(CP) -O binary $^ $@

r: $(BIN)
	st-flash --reset write $^ 0x8000000

clean:
	rm -rf $(BIN) $(ELF)
