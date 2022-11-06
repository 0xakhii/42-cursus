/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 03:35:54 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/06 02:18:12 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void	ft_putptr(unsigned long c, int *len, int in_first)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (in_first)
		ft_putstr("0x", len);
	if (c < 16)
	{
		ft_putchar(hex[c], len);
	}
	else
	{
		ft_putptr(c / 16, len, 0);
		ft_putchar(hex[c % 16], len);
	}
}
