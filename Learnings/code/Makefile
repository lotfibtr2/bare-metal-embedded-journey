 CC=arm-none-eabi-gcc 
MACH=cortex-m4
CFLAGS = -c -mcpu=$(MACH) -std=gnu11 -mthumb -O0

firmware.o:main.c
	$(CC) $(CFLAGS) main.c -o firmware.o