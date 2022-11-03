/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:31:37 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/03 03:40:35 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int c, int *len)
{
	if (c >= 0 && c <= 9)
		ft_putchar(c, *len);
	if (c > 9)
	{
		ft_putnbr(c / 10, *len);
		ft_putchar(c % 10 + '0', *len);
	}
	if (c == -2147483648)
		ft_putstr("-2147483648", *len);
	else
	{
		ft_putchar('-', *len);
		ft_putnbr(c * -1, *len);
	}
}
