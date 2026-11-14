/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 07:21:05 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/13 17:25:12 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		check;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			check = print_format(*(++format), ap);
		else
			check = print_char(*format);
		if (check == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += check;
		format++;
	}
	va_end(ap);
	return (count);
}
