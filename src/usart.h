#pragma once
#include "peripheral.h"

#define USART_BASE  0x40004400UL
#define USART_BRR  (*(volatile uint32_t *)(USART_BASE + 0x0c))
#define USART_CR1  (*(volatile uint32_t *)(USART_BASE + 0x00))
#define USART_TDR  (*(volatile uint32_t *)(USART_BASE + 0x28))
#define USART_ISR  (*(volatile uint32_t *)(USART_BASE + 0x1c))
#define USART_RQR  (*(volatile uint32_t *)(USART_BASE + 0x18))
#define USART_RDR  (*(volatile uint32_t *)(USART_BASE + 0x24))

#define USART1_PIN 9  // PA9
#define USART2_PIN_TX 2  // PA2
#define USART2_PIN_RX 3  // PA3


void enable_usart(int baud, int tx_enable, int rx_enable);
int  poll_usart_txe();
int  poll_usart_rxe();
void usart_send_char(char c);
char usart_receive_char();
