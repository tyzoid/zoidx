#include "display.h"
#include "splash.h"

size_t dtostr(char *out, long i)
{
	size_t length = 0;
	int negative = 0;
	if (i < 0)
	{
		i = -i;
		out[0] = '-';
		negative = 1;
		length++;
	}

	do
	{
		out[length] = (i % 10) + '0';
		i /= 10;

		length++;
	}
	while (i > 0);

	char *start = out;
	char *end = out + length - 1;

	if (negative)
		start++;

	while (start < end)
	{
		char tmp = *start;
		*(start++) = *end;
		*(end--) = tmp;
	}

	out[length] = 0;

	return length;
}

void kernel_main(void) 
{
	display_reset();
	display_splash();
}
