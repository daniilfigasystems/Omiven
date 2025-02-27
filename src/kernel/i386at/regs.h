/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _REGS_H_
#define _REGS_H_

struct registers {
   unsigned int gs, fs, ds, es;
   unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; /* Pushed by pushad. */
   unsigned int int_no, err_code; /* Interrupt number and error code (if applicable) */
   unsigned int eip, cs, eflags; /* Pushed by the processor automatically */
} __attribute__((packed));

typedef struct registers registers_t, *pregisters_t;

#endif /* !_REGS_H_! */