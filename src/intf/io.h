#pragma once

#include <stdint.h>

static __inline unsigned char
inb (unsigned short int port)
{
  unsigned char _v;
  __asm__ __volatile__ ("inb %w1,%0":"=a" (_v):"Nd" (port));
  return _v;
}

static __inline void
outb (unsigned char value, unsigned short int port)
{
  __asm__ __volatile__ ("outb %b0,%w1": :"a" (value), "Nd" (port));
}

void io_wait()
{
  __asm__ __volatile__ ("outb %%al, $0x80" : : "a"(0));
}