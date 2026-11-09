/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 07:30:00 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/09 10:38:36 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *s)
{
	int	count;
	int	check;

	if (!s)
	{
		check = write(1, "(null)", 6);
		if (check == -1)
			return (-1);
		return (check);
	}

	count = 0;
	while (s[count])
	{
		check = write(1, &s[count], 1);
		if (check == -1)
			return (-1);
		count++;
	}
	return (count);
}

int print_digit(long digit, int base, char *b)
{
	unsigned long long n;
	int	count;
	int check;

	if (digit < 0)
	{
		n = (unsigned long long)digit;
		if(write(1, "-", 1) == -1)
			return (-1);
		check = print_digit(-n, base, b);
		if (check == -1)
			return (-1);
		return (check + 1);
	}
	else if (digit < base)
		return (print_char(b[digit]));
	else
	{
			count = print_digit(digit/base, base, b);
			if (count == -1)
				return (-1);
			check = print_char(b[digit % base]);
			if (check == -1)
				return (-1);
		return (count + check);
	}
}

int print_void(void *n, int base, char *b)
{
	int	count;
	int check;
	int check2;
	unsigned long	digit;
	
	if (!n)
		return(write(1, "(nil)", 5));
	digit = (unsigned long)n; 
	if (digit < (unsigned long)base)
	{
        check2 = write(1, "0x", 2);
        if (check2 == -1)
            return (-1);
		return (print_char(b[digit]) + 2);
	}
	else
	{
			count = print_void((void *)(digit/(unsigned long)base), base, b);
			if (count == -1)
				return (-1);
			check = print_char(b[digit % base]);
			if (check == -1)
				return (-1);
		return (count + check);
	}
}

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

int	print_format(char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		return (print_char(va_arg(ap, int)));
	else if (format == 's')
		return  (print_str(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return  (print_digit(va_arg(ap, int), 10, DECIMAL_BASE));
	else if (format == 'x')
		return  (print_digit(va_arg(ap, unsigned int), 16, HEXA_LOWER));
	else if (format == 'X')
		return  (print_digit(va_arg(ap, unsigned int), 16, HEXA_UPEER));
	else if (format == 'u')
		return  (print_u(va_arg(ap, unsigned int), 10, DECIMAL_BASE));
	else if (format == 'p')
		return (print_void(va_arg(ap, void *), 16, HEXA_LOWER));
	else if (format == '\0')
		return (-1);
	else
		return (print_char(format));
}
