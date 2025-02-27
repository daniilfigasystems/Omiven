/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _PIC_H_
#define _PIC_H_

#define PIC1_COMMAND 0x20
#define PIC2_COMMAND 0xa0
#define PIC1_DATA (PIC1_COMMAND + 1)
#define PIC2_DATA (PIC2_COMMAND + 1)
#define PIC_EOI 0x20

#define ICW1_ENABLE_ICW4 0x01
#define ICW1_SINGLE_CASCADE 0x02
#define ICW1_INTERVAL_4_8 0x04
#define ICW1_LEVEL 0x08
#define ICW1_INIT 0x10
#define ICW3_SLAVE_PIC_PRESENT 0x04
#define ICW3_CASCADE 0x02
#define ICW4_8086_MODE 0x01
#define ICW4_AUTO 0x02
#define ICW4_BUFFER_SLAVE 0x08
#define ICW4_BUFFER_MASTER 0x0c
#define ICW4_FULLY_NESTED 0x10

#include <mach/std_types.h>

/* Send End of interrupt */
void pic_eoi(uint8 irq);

/* Initialize PIC */
void pic_init();

#endif /* !_PIC_H_! */