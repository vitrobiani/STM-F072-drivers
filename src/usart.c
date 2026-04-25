#include "usart.h"

static void enable_usart_rx() {
    // Set PA3 as afr
    GPIOA_MODER &= ~(3U << (USART2_PIN_RX * 2));   // clear
    GPIOA_MODER |=  (2U << (USART2_PIN_RX * 2));   // set to afr
    // Set AFR
    GPIOA_AFRL &= ~(0xf << 12); // clear
    GPIOA_AFRL |= (1 << 12); // set the first of the 8 correct bits on

    // Enables
    USART_CR1 |= (1U << 2); // enable RE
}

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

void enable_usart(int baud, int tx_enable, int rx_enable) {
    RCC_APB1ENR |= (1U << 17); // Enable USART2 clock (bit 17 of APB2ENR)
    uint32_t brr = (FREQ / baud);
    USART_BRR = brr;
    if (tx_enable) {
        enable_usart_tx();
    }
    if (rx_enable) {
        enable_usart_rx();
    }
    USART_CR1 |= 1U; // enable UE
}

int poll_usart_txe() {
    return !((USART_ISR >> 7) & 1);
}

int poll_usart_rxe() {
    return !((USART_ISR >> 5) & 1);
}

void usart_send_char(char c) {
    while (poll_usart_txe());
    USART_TDR = c;
}

char usart_receive_char() {
    while (poll_usart_rxe());
    char c = USART_RDR;
    return c;
}
