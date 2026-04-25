#pragma once
#include <stdint.h>

#define FREQ  8000000UL
// Peripheral base addresses
#define RCC_BASE    0x40021000UL
#define GPIOA_BASE  0x48000000UL
#define GPIOC_BASE  0x48000800UL

// RCC registers
#define RCC_AHBENR  (*(volatile uint32_t *)(RCC_BASE  + 0x14))
#define RCC_APB2ENR  (*(volatile uint32_t *)(RCC_BASE  + 0x18))
#define RCC_APB1ENR  (*(volatile uint32_t *)(RCC_BASE  + 0x1c))

// GPIOA registers
#define GPIOA_MODER (*(volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR   (*(volatile uint32_t *)(GPIOA_BASE + 0x14))
#define GPIOA_AFRH  (*(volatile uint32_t *)(GPIOA_BASE + 0x24))
#define GPIOA_AFRL  (*(volatile uint32_t *)(GPIOA_BASE + 0x20))

// GPIOC registers
#define GPIOC_MODER (*(volatile uint32_t *)(GPIOC_BASE + 0x00))
#define GPIOC_IDR   (*(volatile uint32_t *)(GPIOC_BASE + 0x10))

void enable_io_port_a_clock();
void enable_io_port_c_clock();
