KERNEL_BASE = 0x100000;

ENTRY(_start);

SECTIONS 
{
    . = KERNEL_BASE;

    .text.start = .;
    .text BLOCK(4K) : ALIGN(4K) 
    { 
        *(.multiboot);
        *(.text);
    }
    
	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
}