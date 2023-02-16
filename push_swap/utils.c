/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:14:31 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/16 10:06:19 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	msg_er(void)
{
	ft_putstr_fd("\033[1;31m[Error]\n\033[0m", 2);
	exit(1);
}

void	is_int(char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			msg_er();
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb * neg > 2147483647 || nb * neg < -2147483648)
		msg_er();
}
