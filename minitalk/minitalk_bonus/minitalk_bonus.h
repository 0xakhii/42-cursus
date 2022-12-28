/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:27:35 by ojamal            #+#    #+#             */
/*   Updated: 2022/12/28 02:48:39 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_mini
{
	int		pid_server;
}				t_mini;

void	c_send(t_mini *talk,char *mess);
void	s_receive(int binary);
int		ft_strlen(char *str);
void	ft_putstr(char *str, int fd);
void	ft_putnbr(int n);
int		ft_atoi(char *str);
void	msg_er(char *msg);

#endif