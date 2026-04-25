#include "led.h"
#include "button.h"


static void delay(volatile uint32_t n) {
    while (n--);
}

int main(void) {
    enable_led2();
    enable_user_button();

    while (1) {
        if (check_user_button()) {
            toggle_led2();
        }
        delay(200000);
    }
}
