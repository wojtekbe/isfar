BIN=main.bin
ELF=main.elf

CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump

LIB=/home/wojtekbe/lib

STARTUP = $(LIB)/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc_ride7/startup_stm32f40xx.s

CFLAGS = -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork -std=c99 \
		 -I$(LIB)/CMSIS/Device/ST/STM32F4xx/Include/ \
		 -I$(LIB)/CMSIS/Include/ -I$(LIB)/STM32F4xx_StdPeriph_Driver/inc/ \
		 -I. \
		 -DUSE_STDPERIPH_DRIVER -DSTM32F4XX -DHSE_VALUE=8000000 \
		 -Wall -Wl,-T,stm32_flash.ld -g -Os

AFLAGS	= -mcpu=cortex-m4 -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork 
#-mapcs-float use float regs. small increase in code size

SRC = main.c \
	stm32f4xx_it.c \
	system_stm32f4xx.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_usart.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c
	#$(LIB)/STM32F4xx_StdPeriph_Driver/src/misc.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_adc.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_can.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_crc.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_aes.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_des.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_cryp_tdes.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dac.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dbgmcu.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dcmi.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_dma.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_exti.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_flash.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_fsmc.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_md5.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_hash_sha1.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_i2c.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_iwdg.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_pwr.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rng.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rtc.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_sdio.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_spi.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_syscfg.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.c \
	$(LIB)/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_wwdg.c

OBJDIR = .
OBJ = $(SRC:%.c=$(OBJDIR)/%.o) 
OBJ += Startup.o

all: $(BIN)

$(ELF): $(SRC) $(STARTUP)
	$(CC) $(CFLAGS) $^ -lm -lc -lnosys -o $@

$(BIN): $(ELF)
	$(CP) -O binary $^ $@

r: $(BIN)
	st-flash --reset write $^ 0x8000000
	

clean:
	rm -rf $(BIN) $(ELF)
