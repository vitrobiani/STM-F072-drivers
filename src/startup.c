extern unsigned _estack, _sidata, _sdata, _edata, _sbss, _ebss;
extern int main(void);

void Reset_Handler(void) {
    // Copy .data from Flash to RAM
    unsigned *src = &_sidata, *dst = &_sdata;
    while (dst < &_edata) *dst++ = *src++;

    // Zero out .bss
    dst = &_sbss;
    while (dst < &_ebss) *dst++ = 0;

    main();
    while (1);
}

// Minimal vector table — just stack pointer + reset vector
__attribute__((section(".isr_vector")))
void (*const vectors[])(void) = {
    (void *)&_estack,
    Reset_Handler,
};
