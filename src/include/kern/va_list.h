/* 
* Omiven kernel
* Copyright (c) 2025 FigaSystems
* Everyone can copy/modify this project under same name
*/

#ifndef _VA_LIST_H_
#define _VA_LIST_H_

typedef __builtin_va_list va_list;
#define va_start(ap,last) __builtin_va_start(ap, last)
#define va_end(ap) __builtin_va_end(ap)
#define va_arg(ap,type) __builtin_va_arg(ap,type)
#define va_copy(dest, src) __builtin_va_copy(dest,src)

#endif /* !_VA_LIST_H_! */