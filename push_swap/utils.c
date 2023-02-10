/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:14:31 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/10 23:19:06 by ojamal           ###   ########.fr       */
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
	int	sign;

	i = 0;
	sign = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			msg_er();
		if (str[i] == '-')
			sign++;
		if (str[i] == '+' && sign == 0)
			sign++;
		if (ft_isdigit(str[i]) == 0)
			msg_er();
		i++;
	}
	if (sign > 1)
		msg_er();
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) <= -2147483648)
		msg_er();
}
