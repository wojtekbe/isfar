PRG = rpicam
MCU_TARGET = atmega8
DPROG = usbasp
CC = avr-gcc
CFLAGS = -mmcu=$(MCU_TARGET) -Wall -O2
#-DF_CPU=1000000
OBJCOPY = avr-objcopy
UISPFLAGS = -dprog=$(DPROG)
AVRDUDEFLAGS = -p m8 -c $(DPROG)

binfile : $(PRG).c
	$(CC) $(CFLAGS) $(PRG).c -o $(PRG).o
hex: binfile
	avr-objcopy -O ihex $(PRG).o $(PRG).hex
r: hex
	#uisp $(UISPFLAGS) --erase --upload if=$(PRG).hex --verify
	avrdude $(AVRDUDEFLAGS) -Uflash:w:$(PRG).hex -V
clean:
	rm -f $(PRG).o
	rm -f $(PRG).hex
#erase:
#	uisp $(UISPFLAGS) --erase
