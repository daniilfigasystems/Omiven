.intel_syntax noprefix

.set ALIGN,    1<<0             
.set MEMINFO,  1<<1             
.set FLAGS,    ALIGN | MEMINFO 
.set MAGIC,    0x1BADB002      
.set CHECKSUM, -(MAGIC + FLAGS) 

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

.section .text
.global _start
_start:
    call kernel_entry

.global _irq0
.global _irq1
.global _irq2
.global _irq3
.global _irq4
.global _irq5
.global _irq6
.global _irq7
.global _irq8
.global _irq9
.global _irq10
.global _irq11
.global _irq12
.global _irq13
.global _irq14
.global _irq15

_irq0:
    cli
    push 0
    push 0
    jmp _alltraps

_irq1:
    cli
	push 0
    push 1
    jmp _alltraps

_irq2:
    cli
	push 0
    push 2
    jmp _alltraps

_irq3:
    cli
	push 0
    push 3
    jmp _alltraps

_irq4:
    cli
    push 4
    jmp _alltraps

_irq5:
    cli
	push 0
    push 5
    jmp _alltraps

_irq6:
    cli
	push 0
    push 6
    jmp _alltraps

_irq7:
    cli
	push 0
    push 7
    jmp _alltraps

_irq8:
    cli
	push 0
    push 8
    jmp _alltraps

_irq9:
    cli
	push 0
    push 9
    jmp _alltraps

_irq10:
    cli
	push 0
    push 10
    jmp _alltraps

_irq11:
    cli
	push 0
    push 11
    jmp _alltraps

_irq12:
    cli
	push 0
    push 12
    jmp _alltraps

_irq13:
    cli
	push 0
    push 13
    jmp _alltraps

_irq14:
    cli
	push 0
    push 14
    jmp _alltraps

_irq15:
    cli
	push 0
    push 15
    jmp _alltraps

_alltraps:
	pusha
	push ds
	push es
	push fs
	push gs
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov eax, esp
	push eax
	mov eax, _handle_irq
	call eax
	pop eax
	pop gs
	pop fs
	pop es
	pop ds
	popa
	add esp, 8
    iret

.global gdt_install_asm

gdt_install_asm:
	lgdt (global_descriptor_pointer)
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	ret

.global idt_install_asm

idt_install_asm:
	lidt (interrupt_descriptor_pointer)
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	ret

.size _start, . - _start
