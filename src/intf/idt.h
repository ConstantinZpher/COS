#pragma once
#include <stdint.h>
#include <stddef.h>
struct IDT64 {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t ist;
    uint8_t types_attr;
    uint16_t offset_mid;
    uint32_t offset_high;
    uint32_t zero;
};

extern struct IDT64 _idt[256];
extern uint64_t isr1;
extern void load_idt();
void idt_init();