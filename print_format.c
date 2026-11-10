/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 08:59:33 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/10 09:00:19 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char format, va_list ap)
{
	if (format == 'c')
		return (print_char(va_arg(ap, int)));
	else if (format == 's')
		return (print_str(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (print_digit(va_arg(ap, int), 10, DECIMAL_BASE));
	else if (format == 'x')
		return (print_digit(va_arg(ap, unsigned int), 16, HEXA_LOWER));
	else if (format == 'X')
		return (print_digit(va_arg(ap, unsigned int), 16, HEXA_UPEER));
	else if (format == 'u')
		return (print_u(va_arg(ap, unsigned int), 10, DECIMAL_BASE));
	else if (format == 'p')
		return (print_void(va_arg(ap, void *), 16, HEXA_LOWER));
	else if (format == '%')
		return (print_char('%'));
	else if (format == '\0')
		return (-1);
	else
	{
		write(1, "%", 1);
		return (print_char(format) + 1);
	}
}
