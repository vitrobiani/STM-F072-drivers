#include <stdint.h>

// Peripheral base addresses
#define RCC_BASE    0x40021000UL
#define GPIOA_BASE  0x48000000UL
#define GPIOC_BASE  0x48000800UL

// RCC registers
#define RCC_AHBENR  (*(volatile uint32_t *)(RCC_BASE  + 0x14))

// GPIOA registers
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR   (*(volatile uint32_t *)(GPIOA_BASE + 0x14))

#define LED_PIN 5  // PA5 = LD2

static void delay(volatile uint32_t n) {
    while (n--);
}

int main(void) {
    // 1. Enable GPIOA clock (bit 17 of AHBENR)
    RCC_AHBENR |= (1U << 17);

    // 2. Set PA5 as output
    GPIOA_MODER &= ~(3U << (LED_PIN * 2));   // clear
    GPIOA_MODER |=  (1U << (LED_PIN * 2));   // set to output

    while (1) {
        GPIOA_ODR ^= (1U << LED_PIN);  // toggle led
        delay(200000);
    }
}
