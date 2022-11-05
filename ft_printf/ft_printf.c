/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:19:00 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/05 19:20:37 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percentsigne(va_list ap, const char *c, int *len)
{
	int	index;

	index = 0;
	while (c[index] != '\0')
	{
		if (c[++index] == '%')
		{
			if (c[index] == 'c')
				ft_putchar(va_arg(ap, int), len);
			if (c[index] == 's')
				ft_putstr(va_arg(ap, char *), len);
			if ((c[index] == 'i'
					|| c[index] == 'd'))
				ft_putnbr(va_arg(ap, int), len);
			if (c[index] == 'u')
				ft_putunsigned(va_arg(ap, unsigned int), len);
			if (c[index] == 'p')
				ft_putptr(va_arg(ap, int), len);
			if (c[index] == 'x')
				ft_puthex_lower(va_arg(ap, int), len);
			if (c[index] == 'X')
				ft_puthex_upper(va_arg(ap, int), len);
			if (c[index] == '%')
				ft_putchar(va_arg(ap, int), len);
		}
		else
			ft_putchar(c[index], len);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, str);
	percentsigne(ap, str, &len);
	va_end(ap);
	return (len);
}
