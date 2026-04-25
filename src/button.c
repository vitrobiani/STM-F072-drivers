#include "button.h"

void enable_user_button() {
    GPIOC_MODER &= ~(3U << (USER_BUTTON_PIN * 2));   // 00 for intput
}

int check_user_button() {
    return !((GPIOC_IDR >> USER_BUTTON_PIN) & 1);
}
