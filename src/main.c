#include "led.h"


static void delay(volatile uint32_t n) {
    while (n--);
}

int main(void) {
    enable_led2();

    while (1) {
        toggle_led2();
        delay(2000000);
    }
}
