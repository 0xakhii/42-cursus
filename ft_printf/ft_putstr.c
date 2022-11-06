/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:31:40 by ojamal            #+#    #+#             */
/*   Updated: 2022/11/06 02:08:05 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	index;

	index = 0;
	if (!str)
		ft_putstr("(null)", len);
	while (str && str[index] != '\0')
	{
		ft_putchar(str[index], len);
		index++;
	}
}
