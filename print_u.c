
#include "ft_printf.h"

int print_u(unsigned int digit, int base, char *b)
{
	int count;
	int check;


	if (digit < (unsigned int)base)
		return (print_char(b[digit]));
	else
	{
			count = print_u(digit/base, base, b);
			if (count == -1)
				return (-1);
			check = print_char(b[digit % base]);
			if (check == -1)
				return (-1);
		return (count + check);
	}
}