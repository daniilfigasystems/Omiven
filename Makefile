CC ?= $(PREFIX)gcc
AS ?= $(PREFIX)as
LD ?= $(PREFIX)ld
RM ?= rm

CFLAGS := -ffreestanding -O2 -nostdlib -nostdinc -m32 -Isrc/include -Isrc -g
ASFLAGS := --32
LDFLAGS := -nostdlib -z noexecstack

OBJS := boot.o strings.o printf.o debug.o vga.o startup.o

ifeq ($(ARCH), i386at)
	OBJS += gdt.o idt.o irq.o pic.o
endif

all: $(OBJS) link clean
boot.o:
	$(AS) src/kernel/$(ARCH)/boot/boot.S $(ASFLAGS) -o $@
printf.o:
	$(CC) src/kernel/kern/printf.c -c $(CFLAGS) -o $@
strings.o:
	$(CC) src/kernel/kern/strings.c -c $(CFLAGS) -o $@
debug.o:
	$(CC) src/kernel/kern/debug.c -c $(CFLAGS) -o $@
vga.o:
	$(CC) src/kernel/drivers/video/vga/vga.c -c $(CFLAGS) -o $@
startup.o:
	$(CC) src/kernel/kern/startup.c -c $(CFLAGS) -o $@
gdt.o:
	$(CC) src/kernel/$(ARCH)/gdt.c -c $(CFLAGS) -o $@
idt.o:
	$(CC) src/kernel/$(ARCH)/idt.c -c $(CFLAGS) -o $@
irq.o:
	$(CC) src/kernel/$(ARCH)/irq.c -c $(CFLAGS) -o $@
pic.o:
	$(CC) src/kernel/$(ARCH)/pic.c -c $(CFLAGS) -o $@
link:
	$(LD) $(OBJS) -T linker.ld $(LDFLAGS) -m elf_i386 -o bin/mach_kernel
install:
	cp bin/mach_kernel iso/grub/
clean:
	$(RM) *.o