/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _STRINGS_H_
#define _STRINGS_H_

#include <mach/std_types.h>

/* Compare string s1 and s2 */
int32 strcmp(
    register const char *s1,
    register const char *s2);

/* Copy string */
void strcpy(
    register char *destination,
    register const char *source);

/* Get length of string */
uint32 strlen(
    register const char *s);

/* Copy memory */
void memcpy(
    register void *destination,
    register const void *source,
    uint32 size);

void memset(
    register void *destination,
    uint8 value,
    uint32 size);

#endif /* !_STRINGS_H_! */