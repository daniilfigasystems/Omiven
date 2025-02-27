/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _PORTS_H_
#define _PORTS_H_

#include <mach/std_types.h>

typedef uint16 mach_port_t;

#ifdef __i386__
static inline void mach_outportb(mach_port_t port, uint8 value)
{
    asm volatile("outb %b0, %w1" : : "a"(value), "Nd"(port) : "memory");
}

static inline void mach_outportw(mach_port_t port, uint16 value)
{
    asm volatile("outw %w0, %w1" : : "a"(value), "Nd"(port) : "memory");
}

static inline void mach_outportl(mach_port_t port, uint32 value)
{
    asm volatile("outl %l0, %w1" : : "a"(value), "Nd"(port) : "memory");
}

static inline uint8 mach_inportb(mach_port_t port)
{
    uint8 ret;
    asm volatile ( "inb %w1, %b0" : "=a"(ret) : "Nd"(port) : "memory");

    return ret;
}

static inline uint16 mach_inportw(mach_port_t port)
{
    uint16 ret;
    asm volatile ( "inw %w1, %w0" : "=a"(ret) : "Nd"(port) : "memory");

    return ret;
}

static inline uint32 mach_inportl(mach_port_t port)
{
    uint32 ret;
    asm volatile ( "inl %w1, %l0" : "=a"(ret) : "Nd"(port) : "memory");

    return ret;
}
#endif

#endif /* !_PORTS_H_! */