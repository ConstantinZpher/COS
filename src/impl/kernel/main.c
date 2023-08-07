#include "idt.h"
#include "print.h"

void kernel_main() {
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_clear();
    print_str("Kernel Loaded!\n");
    idt_init();
    while(1);
}