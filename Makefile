# Target microcontroller
MCU = avr128db28

# Compiler and flags
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -Os -Wall -Iinclude

# AVRDUDE settings for flashing
AVRDUDE = avrdude
AVRDUDE_PROGRAMMER = jtag2updi   # Change if using a different programmer
AVRDUDE_PORT = /dev/ttyUSB0      # Change if using a different serial port

# Source files
SRCS = src/main.c src/motor_control.c src/distance_sensor.c src/metal_detector.c src/remotecontroller.c src/wireless_remote.c
OBJS = $(SRCS:.c=.o)

# Output files
TARGET = build/firmware

# Compilation rule
all: $(TARGET).hex

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET).hex: $(TARGET).elf
	avr-objcopy -O ihex $< $@

# Upload to AVR
flash: $(TARGET).hex
	$(AVRDUDE) -c $(AVRDUDE_PROGRAMMER) -p $(MCU) -P $(AVRDUDE_PORT) -U flash:w:$(TARGET).hex:i

# Clean build files
clean:
	rm -f src/*.o build/*

