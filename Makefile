# Compiler
CC = avr-gcc
OBJCOPY = avr-objcopy

# Microcontroller settings
MCU = atmega328p  # Change if using a different AVR
F_CPU = 16000000UL  # Adjust to match your clock speed
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall -Wextra

# Files
SRC = src/main.c src/motor_control.c src/distance_sensor.c src/metal_detector.c src/remotecontroller.c src/wireless_remote.c
OBJ = $(SRC:.c=.o)
TARGET = enel300

# Default target
all: $(TARGET).hex

# Compile
%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

# Link
$(TARGET).elf: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Convert to HEX
$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

# Flash to AVR (adjust port and programmer as needed)
flash: $(TARGET).hex
	avrdude -c arduino -p $(MCU) -P /dev/ttyUSB0 -b 115200 -U flash:w:$(TARGET).hex:i

# Clean build files
clean:
	rm -f src/*.o $(TARGET).elf $(TARGET).hex
