MCU      = atmega328p
F_CPU    = 16000000UL
PORT     = /dev/ttyACM0   # change to /dev/ttyUSB0 or COM3 etc.
BAUD     = 115200          # bootloader baud rate (not UART baud)

CC       = avr-gcc
OBJCOPY  = avr-objcopy
CFLAGS   = -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -Wall

all: main.hex

main.elf: main.c
	$(CC) $(CFLAGS) -o $@ $<

main.hex: main.elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: main.hex
	avrdude -v -p $(MCU) -c arduino -P $(PORT) -b $(BAUD) -U flash:w:main.hex:i

clean:
	rm -f main.elf main.hex

.PHONY: all flash clean
