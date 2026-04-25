#include "peripheral.h"

void enable_io_port_a_clock() {
    // Enable GPIOA clock at bit 17 of AHBENR
    RCC_AHBENR |= (1U << 17);
}

void enable_io_port_c_clock() {
    // Enable GPIOA clock at bit 19 of AHBENR
    RCC_AHBENR |= (1U << 19);
}
