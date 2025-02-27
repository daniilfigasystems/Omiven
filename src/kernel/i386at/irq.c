/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#include <kern/irq.h>
#include <kern/debug.h>
#include <kernel/i386at/idt.h>
#include <kernel/i386at/pic.h>

extern void _irq0();
extern void _irq1();
extern void _irq2();
extern void _irq3();
extern void _irq4();
extern void _irq5();
extern void _irq6();
extern void _irq7();
extern void _irq8();
extern void _irq9();
extern void _irq10();
extern void _irq11();
extern void _irq12();
extern void _irq13();
extern void _irq14();
extern void _irq15();

void *irq_routines[16];

void _handle_irq(registers_t *regs)
{
    pic_eoi(regs->int_no);
}

/* Initialize IRQ */
void irq_init()
{
    pic_init();

    idt_set_gate(32, (uint32)_irq0, 8, 0, 0x8e);
    idt_set_gate(33, (uint32)_irq1, 8, 0, 0x8e);
    idt_set_gate(34, (uint32)_irq2, 8, 0, 0x8e);
    idt_set_gate(35, (uint32)_irq3, 8, 0, 0x8e);
    idt_set_gate(36, (uint32)_irq4, 8, 0, 0x8e);
    idt_set_gate(37, (uint32)_irq5, 8, 0, 0x8e);
    idt_set_gate(38, (uint32)_irq6, 8, 0, 0x8e);
    idt_set_gate(39, (uint32)_irq7, 8, 0, 0x8e);
    idt_set_gate(40, (uint32)_irq8, 8, 0, 0x8e);
    idt_set_gate(41, (uint32)_irq9, 8, 0, 0x8e);
    idt_set_gate(42, (uint32)_irq10, 8, 0, 0x8e);
    idt_set_gate(43, (uint32)_irq11, 8, 0, 0x8e);
    idt_set_gate(44, (uint32)_irq12, 8, 0, 0x8e);
    idt_set_gate(45, (uint32)_irq13, 8, 0, 0x8e);
    idt_set_gate(46, (uint32)_irq14, 8, 0, 0x8e);
    idt_set_gate(47, (uint32)_irq15, 8, 0, 0x8e);

    asm("sti");
}
