/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 03:35:54 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/03 03:41:54 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

void	ft_putptr(int c, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c < 16)
	{
		ft_putstr("0x", *len);
		ft_putchar(hex[c], *len);
	}
	else
	{
		ft_putptr(c / 16, *len);
		ft_putchar(c % 16 + '0', *len);
	}
}
