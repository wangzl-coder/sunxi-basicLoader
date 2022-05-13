OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

SECTIONS
{
	. = 0x00000000;
	. = ALIGN(4);
	.head :
	{
		./Boot0_head.o(.bt0_head)
	}
	.text :
	{
		./Boot0.o(.text*)
		*(.text*)
	}
	.data :
	{
		*(.data*)
	}
	.rodata :
	{
		*(.rodata*)
	}
	.bss :
	{
		*(.bss*)
	}
}