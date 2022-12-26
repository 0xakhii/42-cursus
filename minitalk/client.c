/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:00:35 by ojamal            #+#    #+#             */
/*   Updated: 2022/12/08 15:00:35 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client_send(t_mini *talk, char *msg)
{
	int		index;
	int		bit;
	int		signal;

	index = -1;
	while (++index <= ft_strlen(msg))
	{
		bit = -1;
		signal = 0;
		while (++bit < 7)
		{
			if ((msg[index] >> bit) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(talk->pid_server, signal);
			usleep(100);
		}
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_mini	*talk;

	if (ac != 3)
	{
		ft_putstr("\033[1;31m[ERROR]\033[0m:use ./client <server pid> <msg>.\n");
		exit(1);
	}
	else
	{
		talk = malloc(sizeof(t_mini));
		if (!talk)
		{
			ft_putstr("\033[1;31m[ERROR]\033[0m: allocation failed.\n");
			exit(1);
		}
		talk->pid_server = ft_atoi(av[1]);
		if (talk->pid_server <= 0)
		{
			ft_putstr("\033[1;31m[ERROR]\033[0m: PID >= 0\n");
			free(talk);
			talk = NULL;
			exit(1);
		}
		client_send(talk, av[2]);
	}
	return (free(talk), talk = NULL, 0);
}
