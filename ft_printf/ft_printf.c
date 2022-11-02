/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:19:00 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/02 18:55:45 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handl_percentsigne(char *c)
{
	int	index;

	index = 0;
	while (c[index] == '%')
	{
		index++;
		if (c && c[index] == 'c')
			ft_putchar(c);
		if (c && c[index] == 's')
			ft_putstr(c);
		if (c && (c[index] == 'i'
				|| c[index] == 'd'))
			ft_putnbr(1);
		if (c && c[index] == 'u')
			ft_putunbr(1);
		if (c && c[index] == 'p')
			ft_putptr();
		if (c && c[index] == 'x')
			ft_puthex();
		if (c && c[index] == 'X')
			ft_puthex();
		if (c && c[index] == '%')
			ft_putchar(c);
	}
}

int	ft_printf(const char *str, ...)
{
}
