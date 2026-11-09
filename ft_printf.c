/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 07:21:05 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/08 12:16:01 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	count;
	int	check;
	int i;

	if (!format)
		return (-1);
	 i = 0;
	va_start(ap, format);
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check = print_format(format[i + 1], ap);
			if (check == -1)
				return (-1);
			count = check + count;
			i +=2;
		}
		else
			count += write(1, &format[i++], 1);
	}
		va_end(ap);
		return (count);
}