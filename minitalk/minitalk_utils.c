/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:02:49 by ojamal            #+#    #+#             */
/*   Updated: 2022/12/26 22:43:26 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *str)
{
	int		index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	if (str)
	{
		while (str[index])
		{
			ft_putchar(str[index]);
			index++;
		}
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr >= 0 && nbr <= 9)
		ft_putchar(nbr + '0');
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else if (nbr == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		ft_putchar('-');
		ft_putnbr(nbr * -1);
	}
}

int	ft_atoi(char *str)
{
	int				index;
	int				sign;
	unsigned long	res;

	index = 0;
	sign = 1;
	res = 0;
	while (str[index] == 32 || (str[index] > 8 && str[index] < 14))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index++] == '-')
			sign = sign * -1;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10;
		res = res + (str[index] - '0');
		index++;
	}
	return (res * sign);
}
