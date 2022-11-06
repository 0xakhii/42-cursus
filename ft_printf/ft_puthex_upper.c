/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:09:42 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/06 02:15:21 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_upper(unsigned int c, int *len)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (c < 16)
	{
		ft_putchar(hex[c], len);
	}
	else
	{
		ft_puthex_upper(c / 16, len);
		ft_putchar(hex[c % 16], len);
	}
}
