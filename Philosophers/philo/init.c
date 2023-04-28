/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:51:21 by ojamal            #+#    #+#             */
/*   Updated: 2023/04/28 15:06:29 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(int ac, char **av, t_philo *philo)
{
	philo->nb_philo = ft_atoi(av[1]);
	if (philo->nb_philo < 1 || philo->nb_philo > 200)
	{
		ft_putstr_fd("\033[1;31m[Error]:\033[0;m ", 2);
		ft_putstr_fd("Number of philosophers should be between 1 and 200\n", 2);
		return (1);
	}
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (philo->time_to_die < 60 || philo->time_to_eat < 60
		|| philo->time_to_sleep < 60)
	{
		ft_putstr_fd("\033[1;31m[Error]:\033[0;m ", 2);
		ft_putstr_fd("Time should be greater than 60\n", 2);
		return (1);
	}
	philo->meals = 0;
	if (ac == 6)
		philo->nb_meals = ft_atoi(av[5]);
	else
		philo->nb_meals = -1;
	philo->start_time = curr_time();
	return (0);
}

int	init_philo(t_philo *philo)
{
	int	i;

	i = 0;
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	philo->time = curr_time();
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&(philo->forks[i]), NULL))
			return (printf("ERROR\n"));
		i++;
	}
	pthread_mutex_init(&philo->write, NULL);
	pthread_mutex_init(&philo->incr, NULL);
	return (0);
}

long	curr_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(int times)
{
	time_t	start_time;

	start_time = curr_time();
	while (curr_time() - start_time < times)
		usleep(100);
}
