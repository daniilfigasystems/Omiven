#include <kern/debug.h>
#include <kern/printf.h>
#include <kern/va_list.h>

uint32 count, counthi;

void mach_log(const int8* str, ...)
{
    va_list list;

    va_start(list, str);
    int8 *buff;
    sprintf(buff, "[mach:%d.%d] %s", counthi, count, str);
    printf(buff, 0x07, list);
    va_end(list);

    count++;
    if (count >= 255)
    {
        counthi++;
    }
}