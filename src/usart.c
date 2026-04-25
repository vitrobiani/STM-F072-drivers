#include "usart.h"

static void enable_usart_tx() {
    // Set PA2 as afr
    GPIOA_MODER &= ~(3U << (USART2_PIN_TX * 2));   // clear
    GPIOA_MODER |=  (2U << (USART2_PIN_TX * 2));   // set to afr
    // Set AFR
    GPIOA_AFRL &= ~(0xf << 8); // clear
    GPIOA_AFRL |= (1 << 8); // set the first of the 8 correct bits on
    // Enables
    USART_CR1 |= (1U << 3); // enable TE
}

void enable_usart(int baud) {
    RCC_APB1ENR |= (1U << 17); // Enable USART2 clock (bit 17 of APB2ENR)
    uint32_t brr = (FREQ / baud);
    USART_BRR = brr;
    enable_usart_tx();
    USART_CR1 |= 1U; // enable UE
}

int poll_usart_txe() {
    return !((USART_ISR >> 7) & 1);
}

void usart_send_char(char c) {
    while (poll_usart_txe());
    USART_TDR = c;
}
