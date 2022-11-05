/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:19:00 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/05 19:08:30 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percentsigne(va_list ap, char *c, int *len)
{
	int	index;

	index = 0;
	while (c[index] != '\0')
		index++;
	if (c[index] == '%')
	{
		if (c[index] == 'c')
			ft_putchar(va_arg(ap, int), len);
	// if (c[index] == 's')
		// 	ft_putstr(va_arg(ap, int), len);
		if ((c[index] == 'i'
				|| c[index] == 'd'))
			ft_putnbr(va_arg(ap, int), len);
		if (c[index] == 'u')
			ft_putunsigned(va_arg(ap, int), len);
		if (c[index] == 'p')
			ft_putptr(va_arg(ap, int), len);
		if (c[index] == 'x')
			ft_puthex_lower(va_arg(ap, int), len);
		if (c[index] == 'X')
			ft_puthex_upper(va_arg(ap, int), len);
		if (c[index] == '%')
			ft_putchar(va_arg(ap, int), len);
	}
}

// int	ft_printf(const char *str, ...)
// {
// 	va_list	ap;

// 	va_start(ap, str);
// 	percentsigne(va_arg(ap, int), str, 0);
// 	va_end(ap);
// }
