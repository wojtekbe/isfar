##
## This file is part of the libopencm3 project.
##
## Copyright (C) 2009 Uwe Hermann <uwe@hermann-uwe.de>
##
## This library is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This library is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this library.  If not, see <http://www.gnu.org/licenses/>.
##

BINARY = main

LDSCRIPT = stm32f4-discovery.ld

PREFIX	?= arm-none-eabi
# PREFIX		?= arm-elf
CC		= $(PREFIX)-gcc
LD		= $(PREFIX)-gcc
OBJCOPY		= $(PREFIX)-objcopy
OBJDUMP		= $(PREFIX)-objdump
GDB		= $(PREFIX)-gdb
FLASH		= $(shell which st-flash)

TOOLCHAIN_DIR ?= ../../../../../libopencm3
ifeq ($(wildcard ../../../../../libopencm3/lib/libopencm3_stm32f4.a),)
ifneq ($(strip $(shell which $(CC))),)
TOOLCHAIN_DIR := $(shell dirname `which $(CC)`)/../$(PREFIX)
endif
else
ifeq ($(V),1)
$(info We seem to be building the example in the source directory. Using local library!)
endif
endif

CFLAGS		+= -Os -g \
		   -Wall -Wextra -Wimplicit-function-declaration \
		   -Wredundant-decls -Wmissing-prototypes -Wstrict-prototypes \
		   -Wundef -Wshadow \
		   -I$(TOOLCHAIN_DIR)/include \
		   -fno-common -mcpu=cortex-m4 -mthumb \
		   -mfloat-abi=hard  -MD -DSTM32F4 \
		   -mfpu=fpv4-sp-d16
LDSCRIPT	?= $(BINARY).ld
LDFLAGS		+= --static -lc -lnosys -L$(TOOLCHAIN_DIR)/lib \
			 -L$(TOOLCHAIN_DIR)/lib/stm32/f4 \
		   -T$(LDSCRIPT) -nostartfiles -Wl,--gc-sections \
		   -mthumb -mcpu=cortex-m4 -mthumb -mfloat-abi=hard \
			-mfpu=fpv4-sp-d16
OBJS		+= $(BINARY).o

#LDFLAGS += -Wl,--print-gc-sections


#OOCD		?= openocd
#OOCD_INTERFACE	?= flossjtag
#OOCD_BOARD	?= olimex_stm32_h103
# Black magic probe specific variables
# Set the BMP_PORT to a serial port and then BMP is used for flashing
#BMP_PORT        ?=

# Be silent per default, but 'make V=1' will show all compiler calls.
#ifneq ($(V),1)
#NULL := 2>/dev/null
#else
#endif

.SUFFIXES: .elf .bin .hex .srec .list .images
.SECONDEXPANSION:
.SECONDARY:

all: images

images: $(BINARY).images
flash: $(BINARY).flash

%.images: %.bin %.hex
	#printf "*** $* images generated ***\n"

%.bin: %.elf
	#printf "  OBJCOPY $(*).bin\n"
	$(OBJCOPY) -Obinary $(*).elf $(*).bin

%.hex: %.elf
	#printf "  OBJCOPY $(*).hex\n"
	$(OBJCOPY) -Oihex $(*).elf $(*).hex

%.srec: %.elf
	#printf "  OBJCOPY $(*).srec\n"
	$(OBJCOPY) -Osrec $(*).elf $(*).srec

%.list: %.elf
	#printf "  OBJDUMP $(*).list\n"
	$(OBJDUMP) -S $(*).elf > $(*).list

%.elf: $(OBJS) $(LDSCRIPT) $(TOOLCHAIN_DIR)/lib/libopencm3_stm32f4.a
	#printf "  LD      $(subst $(shell pwd)/,,$(@))\n"
	$(LD) -o $(*).elf $(OBJS) -lopencm3_stm32f4 $(LDFLAGS)

%.o: %.c Makefile
	#printf "  CC      $(subst $(shell pwd)/,,$(@))\n"
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o
	rm -f *.d
	rm -f *.elf
	rm -f *.bin
	rm -f *.hex
	rm -f *.srec
	rm -f *.list

r: $(BINARY).bin
	printf "  FLASH  $<\n"
	st-flash write $< 0x8000000

	
ifeq ($(BMP_PORT),)
ifeq ($(OOCD_SERIAL),)
%.flash: %.hex
	printf "  FLASH   $<\n"
	# IMPORTANT: Don't use "resume", only "reset" will work correctly!
	$(OOCD) -f interface/$(OOCD_INTERFACE).cfg \
		    -f board/$(OOCD_BOARD).cfg \
		    -c "init" -c "reset init" \
		    -c "stm32x mass_erase 0" \
		    -c "flash write_image $(*).hex" \
		    -c "reset" \
		    -c "shutdown" $(NULL)
else
%.flash: %.hex
	printf "  FLASH   $<\n"
	# IMPORTANT: Don't use "resume", only "reset" will work correctly!
	$(OOCD) -f interface/$(OOCD_INTERFACE).cfg \
		    -f board/$(OOCD_BOARD).cfg \
		    -c "ft2232_serial $(OOCD_SERIAL)" \
		    -c "init" -c "reset init" \
		    -c "stm32x mass_erase 0" \
		    -c "flash write_image $(*).hex" \
		    -c "reset" \
		    -c "shutdown" $(NULL)
endif
else
%.flash: %.elf
	printf "  GDB   $(*).elf (flash)\n"
	$(GDB) --batch \
		   -ex 'target extended-remote $(BMP_PORT)' \
		   -x $(TOOLCHAIN_DIR)/scripts/black_magic_probe_flash.scr \
		   $(*).elf
endif

.PHONY: images clean

-include $(OBJS:.o=.d)

