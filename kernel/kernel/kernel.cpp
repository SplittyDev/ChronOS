#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <kernel/tty.h>
#include <kernel/heap.h>
#include <kernel/video.h>

#define _GRAPHICS 0

#if defined(__i386__)
#include <arch/i386/idt.h>
#include <arch/i386/gdt.h>
#include <arch/i386/paging.h>
#include <arch/i386/serial.h>
#include <arch/i386/mouse.h>
#include <arch/i386/keyboard.h>

#include <arch/i386/multiboot.h>

multiboot_info_t *mboot_info;
extern "C"
void kearly (multiboot_info_t *_mboot_info) {
	mboot_info = _mboot_info;
	init_kheap (*(uint32_t *)(mboot_info->mods_addr + 4));
#if _GRAPHICS == 1
	init_video (true);
#else
	init_video (false);
#endif
	printf ("Heap initialized\n");
}
#else
extern "C"
void kearly (void) {
	init_video (false);
}
#endif

extern "C"
void kmain (void) {
#if defined(__i386__)
	init_gdt ();
	puts ("GDT initialized");
	init_idt ();
	puts ("IDT initialized");
	init_paging ();
	puts ("Paging initialized");
	Driver::Serial COM1 (0, "COM1", COM1_PORT);
	const char *serial_test = "Hello Serial World!\n\r";
	COM1.Write (serial_test, strlen (serial_test), 0);
	puts ("Serial initialized");

	init_keyboard ();
	printf ("Keyboard initialized\n");
	init_mouse ();
	printf ("Mouse initialized\n");
	asm volatile ("sti");

#endif
	puts ("\nWelcome to ChronOS, well, the kernel to be more specific.");

#if defined(__i386__)
#if _GRAPHICS == 1
	screen_loop ();
#endif
	for (;;) asm ("hlt");
#endif
}
