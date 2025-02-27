/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#include <kernel/i386at/idt.h>
#include <kern/debug.h>

idtr_t interrupt_descriptor_pointer;
idt_t interrupt_descriptor_table[256];

extern void idt_install_asm();

/* interrupt descriptor table set state */
void idt_set_gate(num, offset, selector, cpu_privilege, gate_type)
    uint16 num;
    vm_address_t offset;
    uint16 selector;
    uint8 cpu_privilege;
    uint8 gate_type;
{
    interrupt_descriptor_table[num].offset_lo = offset & 0xffff;
    interrupt_descriptor_table[num].offset_hi = (offset >> 16) & 0xffff;
    interrupt_descriptor_table[num].present = (cpu_privilege >> 2) & 0x1;
    interrupt_descriptor_table[num].zero = 0;
    interrupt_descriptor_table[num].cpu_privilege = cpu_privilege & 0x4;
    interrupt_descriptor_table[num].gate_type = gate_type & 0xf;
}

/* Install Global descriptor table (private) */
void idt_install()
{
    memset(&interrupt_descriptor_pointer, 0, sizeof(struct idtr));
    memset(&interrupt_descriptor_table, 0, sizeof(struct idt) * 256);

    interrupt_descriptor_pointer.offset = (vm_address_t)&interrupt_descriptor_table;
    interrupt_descriptor_pointer.size = (sizeof(struct idt) * 256) - 1;

    idt_install_asm();
}

/* Initialize Interrupt descriptor table */
void idt_init()
{
    idt_install();
}