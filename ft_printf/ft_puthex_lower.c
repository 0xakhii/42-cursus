/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 03:32:47 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/06 02:15:03 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_lower(unsigned int c, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (c < 16)
	{
		ft_putchar(hex[c], len);
	}
	else
	{
		ft_puthex_lower(c / 16, len);
		ft_putchar(hex[c % 16], len);
	}
}
