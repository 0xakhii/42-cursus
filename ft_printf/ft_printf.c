/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:19:00 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/06 00:59:48 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	percentsigne(va_list ap, char c, int *len)
{
	if (c && c == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (c && c == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if ((c && c == 'i')
		|| (c && c == 'd'))
		ft_putnbr(va_arg(ap, int), len);
	else if (c && c == 'u')
		ft_putunsigned(va_arg(ap, unsigned int), len);
	else if (c && c == 'p')
		ft_putptr(va_arg(ap, int), len);
	else if (c && c == 'x')
		ft_puthex_lower(va_arg(ap, int), len);
	else if (c && c == 'X')
		ft_puthex_upper(va_arg(ap, int), len);
	else if (c && c == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		index;
	int		len;

	va_start(ap, str);
	index = 0;
	len = 0;
	while (str[index])
	{
		if (str[index] == '%')
		{
			index++;
			percentsigne(ap, str[index], &len);
		}
		else
			ft_putchar(va_arg(ap, int), &len);
			index++;
	}
	va_end(ap);
	return (len);
}
