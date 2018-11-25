#include "display.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

static uint16_t *display_buffer = (uint16_t *) 0x000B8000;
static size_t row = 0;
static size_t col = 0;
static uint8_t disp_color = 0x07;

static void display_shift_line()
{
	uint16_t *dest = display_buffer;
	uint16_t *source = display_buffer + VGA_WIDTH;

	while (source < (display_buffer + (VGA_WIDTH * VGA_HEIGHT)))
	{
		*(dest++) = *(source++);
	}
}

void display_set_color(uint8_t color)
{
	disp_color = color;
}

void display_reset()
{
	row = 0;
	col = 0;

	display_set_color(FG_VGA_COLOR_LIGHT_GREY | BG_VGA_COLOR_BLACK);

	while(!row && !col)
		display_putchar(' ');
}

void display_putchar_at(char c, uint8_t color, uint8_t x, uint8_t y)
{
	uint16_t ccode = (((uint16_t) color) << 8) | c;
	display_buffer[x + VGA_WIDTH*y] = ccode;
}

void display_putchar(char c)
{
	display_putchar_at(c, disp_color, col, row);
	if (++col == VGA_WIDTH)
	{
		col = 0;
		if (++row == VGA_HEIGHT)
		{
			display_shift_line();
			row--;
		}
	}
}

void display_write(const char *str, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		if (*str == '\n')
		{
			if (++row == VGA_HEIGHT)
			{
				display_shift_line();
				row--;
				col = 0;
			}
		}
		else
		{
			display_putchar(*str);
		}

		str++;
	}
}

void display_print(const char *str)
{
	while (*str)
	{
		if (*str == '\n')
		{
			if (++row == VGA_HEIGHT)
			{
				display_shift_line();
				row--;
				col = 0;
			}
		}
		else
		{
			display_putchar(*str);
		}

		str++;
	}
}
