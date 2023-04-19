/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:31:02 by ojamal            #+#    #+#             */
/*   Updated: 2023/04/19 01:59:52 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	pthread_mutex_t	*forks;
	int 			right;
	int 			left;
	int 			id;
	pthread_t		thread;
	long			time;
	int				eat_nb;
	long			last_time_eat;
}			t_philo;

void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *str);

#endif