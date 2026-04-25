#pragma once
#include "peripheral.h"

#define USART_BASE  0x40004400UL
#define USART_BRR  (*(volatile uint32_t *)(USART_BASE + 0x0c))
#define USART_CR1  (*(volatile uint32_t *)(USART_BASE + 0x00))
#define USART_TDR  (*(volatile uint32_t *)(USART_BASE + 0x28))
#define USART_ISR  (*(volatile uint32_t *)(USART_BASE + 0x1c))

#define USART1_PIN 9  // PA9
#define USART2_PIN_TX 2  // PA2

void enable_usart(int baud);
int  poll_usart_txe();
void usart_send_char(char c);
