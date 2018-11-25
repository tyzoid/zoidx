ASM=yasm

CC=clang
#CFLAGS=-Wall -Wextra --std=c99 --target=i686-pc-none-elf -march=i686 -ffreestanding -fno-builtin -nostdlib -nostdinc
CFLAGS=-Wall -Wextra --std=c99 --target=i686-pc-none-elf -march=i686 -ffreestanding -fno-builtin -nostdlib

all: kern.iso

bin/kern.bin: src/kstart.o src/kernel.o src/splash.o src/display.o
	$(CC) $(CFLAGS) -T src/klink.ld -o $@ $^

kern.iso: bin/kern.bin
	cp -v bin/kern.bin isodir/boot/kern.bin
	grub-mkrescue -o $@ isodir

%.o: %.s
	yasm -felf32 -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	find . -name '*.o' -exec rm -v \{\} \;

nuke: clean
	find . \( -name '*.bin' -o -name '*.iso' \) -exec rm -v \{\} \;
