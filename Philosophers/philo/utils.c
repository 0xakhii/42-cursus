/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 05:13:50 by ojamal            #+#    #+#             */
/*   Updated: 2023/04/19 03:30:14 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}

int	ft_atoi(const char *str)
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
	if (res > 9223372036854775807 && sign == 1)
		return (-1);
	if (res > 9223372036854775807 && sign == -1)
		return (0);
	return (res * sign);
}
