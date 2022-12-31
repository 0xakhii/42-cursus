/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:23:46 by ojamal            #+#    #+#             */
/*   Updated: 2022/12/31 01:56:35 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	s_receive(int binary)
{
	static int					bit = 0;
	static unsigned char		letter = 0;

	if (binary == SIGUSR2)
		letter |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		write(1, &letter, 1);
		if (!letter)
			ft_putstr("\n", 1);
		letter = 0;
		bit = 0;
	}
	return ;
}

void	s_loop(t_mini *talk)
{
	while (1)
	{
		if ((signal(SIGUSR1, s_receive) == SIG_ERR)
			|| (signal(SIGUSR2, s_receive) == SIG_ERR))
		{
			ft_putstr("\033[1;31m[ERROR]\033[0m: Signal Error.\n", 2);
			free(talk);
			talk = NULL;
			exit(1);
		}
		pause();
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

	(void)av;
	talk = NULL;
	if (ac != 1)
		msg_er("\033[1;31m[ERROR]\033[0m: Use ./server only.\n");
	else
	{
		talk = malloc(sizeof(t_mini));
		if (!talk)
			msg_er("\033[1;31m[ERROR]\033[0m: allocation failed.\n");
		talk->pid_server = getpid();
		ft_putstr("\033[1;32m[SUCCESS]\033[0m: Server ready! PID => ", 1);
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
		s_loop(talk);
	}
	free(talk);
	talk = NULL;
	return (0);
}
