/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#include <kern/strings.h>

/* Compare string s1 and s2 */
int32 strcmp(
    register const char *s1,
    register const char *s2)
{
    register char a, b;

    while (a != '\0')
    {
        a = *s1++, b = *s2++;

        if (a != b)
            return 1;
    }

    return 0;
}

/* Copy string */
void strcpy(
    register char *destination,
    register const char *source)
{
    register char a;

    while (a != '\0')
    {
        a = *source++;
        *destination = a;
        *destination++; 
    }
}

/* Get length of string */
uint32 strlen(
    register const char *s)
{
    uint32 n;

    while (*s++ != '\0')
        n++;
    
    return n;
}

/* Copy memory */
void memcpy(
    register void *destination,
    register const void *source,
    uint32 size)
{
    register unsigned char *a;
    register const unsigned char *b;

    a = destination;
    b = source;

    for (uint32 n = 0; n < size; n++)
        a[n] = b[n];
}

/* Set memory */
void memset(
    register void *destination,
    uint8 value,
    uint32 size)
{
    register unsigned char *a;

    a = destination;

    for (uint32 n = 0; n < size; n++)
        a[n] = value;
}