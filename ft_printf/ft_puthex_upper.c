/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:09:42 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/05 22:08:10 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_upper(int c, int *len)
{
	char	*hex;

	hex = "0123456789ABCDEF";
	if (c < 16)
	{
		ft_putchar(hex[c], len);
	}
	else
	{
		ft_putchar(hex[c / 16], len);
		ft_puthex_upper(hex[c % 16], len);
	}
}
