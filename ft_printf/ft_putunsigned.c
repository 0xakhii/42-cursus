/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 03:27:18 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/06 02:14:25 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int c, int *len)
{
	if (c >= 0 && c <= 9)
		ft_putchar(c + '0', len);
	else
	{
		ft_putnbr(c / 10, len);
		ft_putchar(c % 10 + '0', len);
	}
}
