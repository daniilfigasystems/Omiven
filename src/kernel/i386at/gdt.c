/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#include <kernel/i386at/gdt.h>
#include <kern/strings.h>
#include <kern/debug.h>

gdtr_t global_descriptor_pointer;
gdt_t global_descriptor[3];
gdt_t *code_descriptor = &global_descriptor[1];
gdt_t *data_descriptor = &global_descriptor[2];

extern void gdt_install_asm();

/* global descriptor table set state */
void gdt_set_gate(num, base, limit, flags, access)
    uint8 num;
    vm_address_t base;
    uint32 limit;
    uint8 flags;
    uint8 access;
{
    global_descriptor[num].base_lo = base & 0xffff;
    global_descriptor[num].base_mi = (base >> 16) & 0xff;
    global_descriptor[num].base_hi = (base >> 24) & 0xff;
    global_descriptor[num].limit_lo = limit & 0xffff;
    global_descriptor[num].limit_hi = (limit >> 16) & 0xf;
    global_descriptor[num].flags = flags;
    global_descriptor[num].access = access;
}

/* Install Global descriptor table (private) */
void gdt_install()
{
    memset(&global_descriptor_pointer, 0, sizeof(struct gdtr));

    global_descriptor_pointer.offset = (vm_address_t)&global_descriptor;
    global_descriptor_pointer.size = (sizeof(struct gdt) * 3) - 1;

    mach_log("size:0x%x offset:0x%x\n", global_descriptor_pointer.size, global_descriptor_pointer.offset);
    mach_log("flags:0x%x access:0x%x base:0x%x limit:%x\n", global_descriptor[1].flags, global_descriptor[1].access, global_descriptor[1].base_lo | (global_descriptor[1].base_mi << 16) | (global_descriptor[1].base_hi << 24), (uint32)(global_descriptor[1].limit_lo | ((global_descriptor[1].limit_hi << 16) & 0xf)));
    gdt_install_asm();
}

/* Initialize Global descriptor table */
void gdt_init()
{
    asm("cli");

    memset(&global_descriptor, 0, (sizeof(struct gdt) * 3) - 1);

    gdt_set_gate(
        1, 
        0, 
        0xffffffff,
        (1 << G_GRANULARITY_BIT) | (1 << G_SIZE_BIT),
        (1 << G_PRESENT_BIT) | (1 << G_DESCRIPTOR_TYPE_BIT) | (1 << G_EXECUTABLE_BIT) | (1 << G_READ_WRITE_BIT));

    gdt_set_gate(
        2, 
        0, 
        0xffffffff,
        (1 << G_GRANULARITY_BIT) | (1 << G_SIZE_BIT),
        (1 << G_PRESENT_BIT) | (1 << G_DESCRIPTOR_TYPE_BIT) | (0 << G_EXECUTABLE_BIT) | (1 << G_READ_WRITE_BIT));

    gdt_install();
}