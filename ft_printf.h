/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 08:55:46 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/13 07:11:44 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# define DECIMAL_BASE "0123456789"
# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPEER "0123456789ABCDEF"

int	ft_printf(const char *format, ...);
int	print_format(char c, va_list ap);
int	print_char(int c);
int	print_str(char *s);
int	print_digit(long digit, int base, char *b);
int	print_void(void *n, unsigned long base, char *b);
int	print_unsigned(unsigned int digit, unsigned int base, char *b);

#endif
