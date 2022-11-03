/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:19:00 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/03 03:31:25 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percentsigne(char *c, int *len)
{
	int	index;

	index = 0;
	while (c[index] == '%')
	{
		index++;
		if (c && c[index] == 'c')
			ft_putchar(c, *len);
		if (c && c[index] == 's')
			ft_putstr(c, *len);
		if (c && (c[index] == 'i'
				|| c[index] == 'd'))
			ft_putnbr(c, *len);
		if (c && c[index] == 'u')
			ft_putunsigned(c, *len);
		if (c && c[index] == 'p')
			ft_putptr(c, *len);
		if (c && c[index] == 'x')
			ft_puthex(c, *len);
		if (c && c[index] == 'X')
			ft_puthex(c, *len);
		if (c && c[index] == '%')
			ft_putchar('%', *len);
	}
}

int	ft_printf(const char *str, ...)
{
}
