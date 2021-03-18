# File:   Makefile
# Author: M. P. Hayes, UCECE
# Date:   12 Sep 2010
# Descr:  Makefile for game

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I../../utils -I../../fonts -I../../drivers -I../../drivers/avr
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: game.out


# Compile: create object files from C source files.
game.o: game.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

<<<<<<< HEAD
=======
ir_uart.o: ../../drivers/avr/ir_uart.c ../../drivers/avr/ir_uart.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/avr/timer0.h ../../drivers/avr/usart1.h
	$(CC) -c $(CFLAGS) $< -o $@

>>>>>>> 6beaf83c6a2e41834932be9da6074550f6110418
system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../drivers/avr/pio.c ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

<<<<<<< HEAD
timer.o: ../../drivers/avr/timer.c ../../drivers/avr/timer.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

=======
prescale.o: ../../drivers/avr/prescale.c ../../drivers/avr/prescale.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/timer.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer0.o: ../../drivers/avr/timer0.c ../../drivers/avr/bits.h ../../drivers/avr/prescale.h ../../drivers/avr/system.h ../../drivers/avr/timer0.h
	$(CC) -c $(CFLAGS) $< -o $@

usart1.o: ../../drivers/avr/usart1.c ../../drivers/avr/system.h ../../drivers/avr/usart1.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../drivers/display.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../drivers/ledmat.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

>>>>>>> 6beaf83c6a2e41834932be9da6074550f6110418
pacer.o: ../../utils/pacer.c ../../utils/pacer.h ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/navswitch.h ../../drivers/avr/system.h ../../drivers/avr/delay.h ../../drivers/avr/pio.h
	$(CC) -c $(CFLAGS) $< -o $@

<<<<<<< HEAD
# Link: create ELF output file from object files.
game.out: game.o system.o pio.o timer.o pacer.o navswitch.o
=======
font.o: ../../utils/font.c ../../drivers/avr/system.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../utils/tinygl.c ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

led.o: led.c ../../drivers/avr/system.h ../../drivers/avr/pio.h led.h
	$(CC) -c $(CFLAGS) $< -o $@

navs.o: navs.c ../../drivers/avr/system.h ../../drivers/avr/pio.h ../../drivers/navswitch.h navs.h
	$(CC) -c $(CFLAGS) $< -o $@

end.o: end.c ../../drivers/avr/system.h ../../utils/pacer.h ../../utils/font.h ../../drivers/avr/ir_uart.h ../../drivers/navswitch.h ../../utils/tinygl.h navs.h end.h led.h
	$(CC) -c $(CFLAGS) $< -o $@

move.o: move.c ../../drivers/avr/system.h end.h move.h
	$(CC) -c $(CFLAGS) $< -o $@

transceive.o: transceive.c ../../drivers/avr/system.h end.h ../../drivers/avr/ir_uart.h transceive.h
	$(CC) -c $(CFLAGS) $< -o $@


# Link: create ELF output file from object files.
game.out: game.o ir_uart.o system.o pio.o prescale.o timer.o timer0.o usart1.o display.o ledmat.o pacer.o navswitch.o font.o tinygl.o led.o navs.o end.o move.o transceive.o
>>>>>>> 6beaf83c6a2e41834932be9da6074550f6110418
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
<<<<<<< HEAD
clean: 
=======
clean:
>>>>>>> 6beaf83c6a2e41834932be9da6074550f6110418
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: game.out
	$(OBJCOPY) -O ihex game.out game.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash game.hex; dfu-programmer atmega32u2 start

<<<<<<< HEAD

=======
>>>>>>> 6beaf83c6a2e41834932be9da6074550f6110418
