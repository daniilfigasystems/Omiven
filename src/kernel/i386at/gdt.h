/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _GDT_H_
#define _GDT_H_

#include <mach/std_types.h>

#define G_PRESENT_BIT 7
#define G_DPL_BIT 5
#define G_DESCRIPTOR_TYPE_BIT 4
#define G_EXECUTABLE_BIT 3
#define G_DIRECTION_BIT 2
#define G_READ_WRITE_BIT 1
#define G_ACCESS_BIT 0
#define G_GRANULARITY_BIT 3
#define G_SIZE_BIT 2
#define G_LONG_MODE_BIT 1

struct gdtr
{
    uint16 size;
    vm_offset_t offset;
} __attribute__((packed));

typedef struct gdtr gdtr_t;

struct gdt
{
    uint16 limit_lo;
    uint16 base_lo;
    uint8 base_mi;
    uint8 access;
    uint8 limit_hi : 4;
    uint8 flags : 4;
    uint8 base_hi;
} __attribute__((packed));

typedef struct gdt gdt_t;

/* General descriptor table set state */
void gdt_set_gate(uint8 num, vm_address_t base, uint32 limit, uint8 flags, uint8 access);

/* Initialize General descriptor table */
void gdt_init();

#endif /* !_GDT_H_! */