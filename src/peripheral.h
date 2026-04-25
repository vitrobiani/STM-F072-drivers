#pragma once
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
#define GPIOC_MODER (*(volatile uint32_t *)(GPIOC_BASE + 0x00))
#define GPIOC_IDR   (*(volatile uint32_t *)(GPIOC_BASE + 0x10))

void enable_io_port_a_clock();
void enable_io_port_c_clock();
