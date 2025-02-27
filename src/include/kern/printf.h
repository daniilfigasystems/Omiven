/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <kern/va_list.h>
#include <kern/strings.h>
#include <mach/video.h>

/*
 * vasprintf()
 */
uint32
vasprintf(char * buf, const char *fmt, va_list args);

/**
 * (Kernel) Print a formatted string.
 * %s, %c, %x, %d, %%
 *
 * @param fmt Formatted string to print
 * @param ... Additional arguments to format
 */
#ifndef EXTREME_KPRINTF_DEBUGGING
int
printf(
		const char *fmt, uint8 color,
		...
	   );
#else
int
_kprintf(
		char * file,
		int line,
		const char *fmt,
		...
	   );
#endif

int
sprintf(
		char * buf,
		const char *fmt,
		...
	   );

#endif /* !_PRINTF_H_! */