#include "led.h"
#include "button.h"
#include "usart.h"


static void delay(volatile uint32_t n) {
    while (n--);
}
static void send_hello();

int main(void) {
    enable_led2();
    enable_user_button();
    enable_usart(9600, 1, 1);

    send_hello();
    while (1) {
        char c = usart_receive_char();
        if (c == 'O') {
            GPIOA_ODR ^= (1U << LED_PIN);  // toggle
        }
        // if (check_user_button()) {
        //     toggle_led2();
        //     usart_send_char('O');
        // }
        delay(200000);
    }
}

static void send_hello() {
    usart_send_char('H');
    usart_send_char('e');
    usart_send_char('l');
    usart_send_char('l');
    usart_send_char('o');
    usart_send_char('!');
}
