/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:00:10 by ojamal            #+#    #+#             */
/*   Updated: 2022/12/08 15:00:10 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_mini
{
	int		pid_server;
	int		pid_client;
}				t_mini;

t_mini	*client_initiate(void);
void	client_send(t_mini *talk, char *mess);
t_mini	*server_initiate(void);
void	server_receive(int binary);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_atoi(char *str);

#endif