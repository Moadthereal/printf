/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majnaou <majnaou@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 11:04:34 by majnaou           #+#    #+#             */
/*   Updated: 2026/11/13 11:13:27 by majnaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_null(char *s)
{
	int	check;
	int	count;

	count = 0;
	while (s[count])
	{
		check = write(1, &s[count], 1);
		if (check != 1)
			return (-1);
		count++;
	}
	return (count);
}
