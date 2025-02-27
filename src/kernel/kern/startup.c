/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#include <mach/video.h>
#include <kern/printf.h>
#include <mach/std_types.h>
#include <kern/debug.h>
#include <kernel/i386at/gdt.h>
#include <kernel/i386at/idt.h>
#include <kernel/i386at/pic.h>
#include <kern/irq.h>

int kernel_entry(unsigned int magic)
{
    video_reset();
    printf("                           Omiven Mach Version 0.001                            \n", 0x67);
    mach_log("Starting Mach\n");
    gdt_init();
    idt_init();
    irq_init();

    for (;;)
        ;
}