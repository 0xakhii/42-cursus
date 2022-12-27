/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:23:46 by ojamal            #+#    #+#             */
/*   Updated: 2022/12/27 19:52:03 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

// letter += ((binary & 1) << bit++);

void	s_receive(int binary)
{
	static int					bit = 0;
	static unsigned char		letter = 0;

	if (binary == SIGUSR2)
		letter |= 1 << bit;
	bit++;
	if (bit == 7)
	{
		write(1, &letter, 1);
		if (!letter)
			ft_putstr("\n");
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
			ft_putstr("\033[1;31m[ERROR]\033[0m: Signal Error.\n");
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
	ft_putstr(msg);
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
			msg_er("\033[1;31m[ERROR]\033[0m: Use ./server only.\n");
		talk->pid_server = getpid();
		ft_putstr("\033[1;32m[SUCCESS]\033[0m: Server ready! PID => ");
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
		s_loop(talk);
	}
	free(talk);
	talk = NULL;
	return (0);
}
