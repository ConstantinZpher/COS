#include "idt.h"
#include "print.h"
#include "io.h"
#include "pic.h"
#include "kbset1.h"

void idt_init() {
    for(uint64_t t = 0; t < 256; t++) {
        _idt[t].zero = 0;
        _idt[t].offset_low = (uint16_t)(((uint64_t)&isr1 & 0x000000000000ffff));
        _idt[t].offset_mid = (uint16_t)(((uint64_t)&isr1 & 0x00000000ffff0000) >> 16);
        _idt[t].offset_high = (uint32_t)(((uint64_t)&isr1 & 0xffffffff00000000) >> 32);
        _idt[t].ist = 0;
        _idt[t].selector = 0x08;
        _idt[t].types_attr = 0x8e;
    }
    remap_pic();
    outb(0x21, 0xfd);
    outb(0xa1, 0xff);
    load_idt();
}

extern void isr1_handler() {
    uint8_t scancode = inb(0x60);
    print_char(SCANCODE_LOOKUP_TABLE[scancode]);
    outb(0x20, 0x20);
    outb(0xa0, 0x20);
}