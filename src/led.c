#include "led.h"
#include <peripheral.h>

void enable_led2() {
    enable_io_port_a_clock();

    // Set PA5 as output
    GPIOA_MODER &= ~(3U << (LED_PIN * 2));   // clear
    GPIOA_MODER |=  (1U << (LED_PIN * 2));   // set to output
}

void toggle_led2() {
    GPIOA_ODR ^= (1U << LED_PIN);  // toggle led
}

