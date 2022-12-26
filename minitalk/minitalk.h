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
}				t_mini;

void	c_send(t_mini *talk, char *mess);
void	s_receive(int binary);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
int		ft_atoi(char *str);
void	msg_er(char *msg);

#endif