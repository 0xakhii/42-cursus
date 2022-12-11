/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:49 by ojamal            #+#    #+#             */
/*   Updated: 2022/12/08 15:01:49 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_mini	*server_initiate(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
	{
		ft_putstr("\033[0;31m[ERROR]\033[0m: Out of memory! malloc() failed.\n");
		exit(EXIT_FAILURE);
	}
	talk->pid_server = 0;
	talk->pid_client = 0;
	return (talk);
}

void	server_receive(int binary)
{
	static int		bit = 0;
	static char		letter = 0;

	letter += ((binary & 1) << bit++);
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

void	server_loop(t_mini *talk)
{
	while (1)
	{
		if ((signal(SIGUSR1, server_receive) == SIG_ERR)
			|| (signal(SIGUSR2, server_receive) == SIG_ERR))
		{
			ft_putstr("\033[0;31m[ERROR]\033[0m: Signal error.\n");
			free(talk);
			talk = NULL;
			exit(EXIT_FAILURE);
		}
		pause();
	}
	return ;
}

int	main(int ac, char *av[])
{
	t_mini	*talk;

	(void)av;
	talk = NULL;
	if (ac != 1)
	{
		ft_putstr("\033[0;31m[ERROR]\033[0m: Use ./server with 1 argument only.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = server_initiate();
		talk->pid_server = getpid();
		ft_putstr("\033[0;32m[SUCCESS]\033[0m: Server ready! PID: ");
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
		server_loop(talk);
	}
	free(talk);
	talk = NULL;
	return (0);
}