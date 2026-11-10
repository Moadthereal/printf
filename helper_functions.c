/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 07:30:00 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/10 07:41:52 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	print_digit(long digit, int base, char *b)
{
	int	count;
	int	check;

	if (digit < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		check = print_digit(-digit, base, b);
		if (check == -1)
			return (-1);
		return (check + 1);
	}
	else if (digit < base)
		return (print_char(b[digit]));
	else
	{
		count = print_digit(digit / base, base, b);
		if (count == -1)
			return (-1);
		check = print_char(b[digit % base]);
		if (check == -1)
			return (-1);
		return (count + check);
	}
}

int	print_void(void *n, int base, char *b)
{
	unsigned long	digit;
	int				count;
	int				check;

	if (!n)
		return (write(1, "(nil)", 5));
	digit = (unsigned long)n;
	if (digit < (unsigned long)base)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (print_char(b[digit]) == -1)
			return (-1);
		return (3);
	}
	else
	{
		count = print_void((void *)(digit / (unsigned long)base), base, b);
		if (count == -1)
			return (-1);
		check = print_char(b[digit % base]);
		if (check == -1)
			return (-1);
		return (count + check);
	}
}

int	print_u(unsigned int digit, int base, char *b)
{
	int	count;
	int	check;

	if (digit < (unsigned int)base)
		return (print_char(b[digit]));
	else
	{
		count = print_u(digit / base, base, b);
		if (count == -1)
			return (-1);
		check = print_char(b[digit % base]);
		if (check == -1)
			return (-1);
		return (count + check);
	}
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}
