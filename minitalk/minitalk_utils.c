/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:02:49 by ojamal            #+#    #+#             */
/*   Updated: 2022/12/09 22:26:43 by ojamal           ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	long int	index;
	long int	nbr;
	long int	neg;

	index = 0;
	nbr = 0;
	neg = 1;
	while (str[index] == ' ' || str[index] == '\t' || str[index] == '\n'
		|| str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			neg = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		nbr = nbr * 10 + (str[index] - 48);
		index++;
	}
	return (nbr * neg);
}