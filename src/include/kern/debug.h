/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <mach/std_types.h>
#include <kern/printf.h>

/* Log kernel */
void mach_log(const int8* str, ...);

#endif /* !_DEBUG_H_! */