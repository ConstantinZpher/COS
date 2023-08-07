global long_mode_start
extern kernel_main

section .text
bits 64
long_mode_start:

    ; load null into all data segmant registers
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ;%include "src/impl/x86_64/IDT.asm"
    call kernel_main
    hlt
    