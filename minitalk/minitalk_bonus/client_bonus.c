/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:23:11 by ojamal            #+#    #+#             */
/*   Updated: 2022/12/28 02:56:42 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	c_send(t_mini *talk,char *msg)
{
	int		index;
	int		bit;
	int		signal;

	index = -1;
	while (++index <= ft_strlen(msg))
	{
		bit = -1;
		signal = 0;
		while (++bit < 8)
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

void	msg_er(char *msg)
{
	ft_putstr(msg, 2);
	exit(1);
}

int	main(int ac, char *av[])
{
	t_mini	*talk;

	talk = NULL;
	if (ac != 3)
		msg_er("\033[1;31m[ERROR]\033[0m:use ./client <server pid> <msg>.\n");
	else
	{
		talk = malloc(sizeof(t_mini));
		if (!talk)
			msg_er("\033[1;31m[ERROR]\033[0m: allocation failed.\n");
		talk->pid_server = ft_atoi(av[1]);
		if (talk->pid_server <= 0)
		{
			ft_putstr("\033[1;31m[ERROR]\033[0m: PID is >= 0\n", 2);
			free(talk);
			talk = NULL;
			exit(1);
		}
		c_send(talk, av[2]);
	}
	return (free(talk), talk = NULL, 0);
}
