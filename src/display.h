#ifndef _ZOIDX_DISPLAY_H
#define _ZOIDX_DISPLAY_H

#include <stdint.h>
#include <stddef.h>

#define FG_VGA_COLOR_BLACK 0x00
#define FG_VGA_COLOR_BLUE 0x01
#define FG_VGA_COLOR_GREEN 0x02
#define FG_VGA_COLOR_CYAN 0x03
#define FG_VGA_COLOR_RED 0x04
#define FG_VGA_COLOR_MAGENTA 0x05
#define FG_VGA_COLOR_BROWN 0x06
#define FG_VGA_COLOR_LIGHT_GREY 0x07
#define FG_VGA_COLOR_DARK_GREY 0x08
#define FG_VGA_COLOR_LIGHT_BLUE 0x09
#define FG_VGA_COLOR_LIGHT_GREEN 0x0A
#define FG_VGA_COLOR_LIGHT_CYAN 0x0B
#define FG_VGA_COLOR_LIGHT_RED 0x0C
#define FG_VGA_COLOR_LIGHT_MAGENTA 0x0D
#define FG_VGA_COLOR_LIGHT_BROWN 0x0E
#define FG_VGA_COLOR_WHITE 0x0F

#define BG_VGA_COLOR_BLACK 0x00
#define BG_VGA_COLOR_BLUE 0x10
#define BG_VGA_COLOR_GREEN 0x20
#define BG_VGA_COLOR_CYAN 0x30
#define BG_VGA_COLOR_RED 0x40
#define BG_VGA_COLOR_MAGENTA 0x50
#define BG_VGA_COLOR_BROWN 0x60
#define BG_VGA_COLOR_LIGHT_GREY 0x70
#define BG_VGA_COLOR_DARK_GREY 0x80
#define BG_VGA_COLOR_LIGHT_BLUE 0x90
#define BG_VGA_COLOR_LIGHT_GREEN 0xA0
#define BG_VGA_COLOR_LIGHT_CYAN 0xB0
#define BG_VGA_COLOR_LIGHT_RED 0xC0
#define BG_VGA_COLOR_LIGHT_MAGENTA 0xD0
#define BG_VGA_COLOR_LIGHT_BROWN 0xE0
#define BG_VGA_COLOR_WHITE 0xF0

void display_reset();
void display_putchar_at(char c, uint8_t color, uint8_t x, uint8_t y);
void display_set_color(uint8_t color);
void display_putchar(char c);
void display_write(const char *str, size_t size);
void display_print(const char *str);

#endif

