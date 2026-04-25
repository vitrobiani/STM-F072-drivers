PROJECT_NAME := stm-drivers
SRC_DIR    := src
OBJ_DIR    := objects
TARGET_DIR := target

# Compiler and tools
CC     := arm-none-eabi-gcc
OCOPY  := arm-none-eabi-objcopy
MCU    := -mcpu=cortex-m0 -mthumb

CFLAGS  := $(MCU) -O2 -Wall -Wextra -ffreestanding -nostdlib -I$(SRC_DIR)
LDFLAGS := $(MCU) -T stm32f072rb.ld -nostdlib 

TARGET := $(TARGET_DIR)/proc

# Find sources
C_SOURCES := $(wildcard $(SRC_DIR)/*.c)
H_FILES := $(wildcard *.h)
C_FILES := $(wildcard *.c)
OBJECTS   := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(C_SOURCES))

all: setup $(TARGET).bin

setup:
	@mkdir -p $(SRC_DIR) $(OBJ_DIR) $(TARGET_DIR)
	@mv -f $(C_FILES) $(H_FILES) $(SRC_DIR) 2>/dev/null || true

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link
$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^ -lgcc

# Binary
$(TARGET).bin: $(TARGET).elf
	$(OCOPY) -O binary $< $@

flash: $(TARGET).bin
	st-flash write $< 0x08000000

clean:
	rm -rf $(OBJ_DIR) $(TARGET_DIR)

.PHONY: all setup flash clean
