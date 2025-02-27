/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _IDT_H_
#define _IDT_H_

#include <mach/std_types.h>

struct idtr 
{
    uint16 size;
    vm_offset_t offset;
} __attribute__((packed));

typedef struct idtr idtr_t;

struct idt
{
    uint16 offset_lo;
    uint16 selector;
    uint8 reserved;
    uint8 gate_type : 4;
    uint8 zero : 1;
    uint8 cpu_privilege : 2;
    uint8 present : 1;
    uint16 offset_hi;
} __attribute__((packed));

typedef struct idt idt_t;

/* interrupt descriptor table set state */
void idt_set_gate(uint16 num, vm_address_t offset, uint16 selector, uint8 cpu_privilege, uint8 gate_type);

/* Initialize Interrupt descriptor table */
void idt_init();

#endif /* !_IDT_H_! */