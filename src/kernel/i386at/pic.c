/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#include <kernel/i386at/pic.h>
#include <mach/ports.h>

/* Send End of interrupt */
void pic_eoi(uint8 irq)
{
    if (irq >= 8)
        mach_outportb(PIC2_COMMAND, PIC_EOI);
    else
        mach_outportb(PIC1_COMMAND, PIC_EOI);
}

/* Initialize PIC */
void pic_init()
{
    mach_outportb(PIC1_COMMAND, ICW1_INIT | ICW1_ENABLE_ICW4);
    mach_outportb(0x80, 0);
    mach_outportb(PIC2_COMMAND, ICW1_INIT | ICW1_ENABLE_ICW4);
    mach_outportb(0x80, 0);
    mach_outportb(PIC1_DATA, 0x20);
    mach_outportb(0x80, 0);
    mach_outportb(PIC2_DATA, 0x28);
    mach_outportb(0x80, 0);
    mach_outportb(PIC1_DATA, ICW3_SLAVE_PIC_PRESENT);
    mach_outportb(0x80, 0);
    mach_outportb(PIC2_DATA, ICW3_CASCADE);
    mach_outportb(0x80, 0);
    mach_outportb(PIC1_DATA, ICW4_8086_MODE);
    mach_outportb(0x80, 0);
    mach_outportb(PIC2_DATA, ICW4_8086_MODE);
    mach_outportb(0x80, 0);
    mach_outportb(PIC1_DATA, 0);
    mach_outportb(PIC2_DATA, 0);
}