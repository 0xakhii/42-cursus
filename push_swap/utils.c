/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:14:31 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/19 04:00:25 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	msg_er(void)
{
	ft_putstr_fd("\033[1;31m[Error]\n\033[0m", 2);
	exit(1);
}

char	*joinargs(int argc, char **argv)
{
	int		i;
	int		j;
	char	*args;

	i = 1;
	args = NULL;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
			msg_er();
		args = ft_strjoin(args, argv[i]);
		args = ft_strjoin(args, " ");
		i++;
	}
	return (args);
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

void	is_dup(char **num)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (num[i])
	{
		j = i + 1;
		while (num[j])
		{
			if (ft_atoi(num[i]) == ft_atoi(num[j]))
				msg_er();
			j++;
		}
		i++;
	}
}
