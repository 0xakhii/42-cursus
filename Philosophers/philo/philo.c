/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:39:24 by ojamal            #+#    #+#             */
/*   Updated: 2023/04/19 01:59:50 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	curr_time()
{
	struct	timeval time;

	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}


t_philo	init_philo(int ac, char **av)
{
	t_philo 		philo;
	int				i;

	i = 0;
	philo.nb_philo = ft_atoi(av[1]);
	philo.time_to_die = ft_atoi(av[2]);
	philo.time_to_eat = ft_atoi(av[3]);
	philo.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		philo.nb_meals = ft_atoi(av[5]);
	else
		philo.nb_meals = -1;
	philo.forks = malloc(sizeof(pthread_mutex_t) * philo.nb_philo);
		philo.time = curr_time();
		if (pthread_mutex_init(&philo.forks[i], NULL) != 0)
		{
			ft_putstr_fd("\033[1;31m[Error]:\033[0;m ", 2);
			ft_putstr_fd("Error while creating mutex\n", 2);
		}
		philo.id = i + 1;
	philo.right = 0;
	philo.left = 1;
	philo.last_time_eat = philo.time;
	philo.thread = malloc(sizeof(pthread_t) * philo.nb_philo);
	return (philo);
}

void	time_to_die(t_philo *philo)
{
	long	time;

	time = curr_time();
	if (time - philo->time >= philo->time_to_die)
		printf("%ld philo %d died\n", time - philo->time, philo->id);
}
      
void	*philo_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while(1)
	{
		pthread_mutex_lock(&philo->forks[philo->right]);
		pthread_mutex_lock(&philo->forks[philo->left]);
		printf("%ld philo %d has taken a fork\n", curr_time() - philo->time, philo->id);
		printf("%ld philo %d has taken a fork\n", curr_time() - philo->time, philo->id);
		printf("%ld philo %d is eating\n", curr_time() - philo->time, philo->id);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->forks[philo->right]);
		pthread_mutex_unlock(&philo->forks[philo->left]);
		printf("%ld philo %d is sleeping\n", curr_time() - philo->time, philo->id);
		usleep(philo->time_to_sleep * 1000);
		printf("%ld philo %d is thinking\n", curr_time() - philo->time, philo->id);
	}
}

void	create_th(t_philo *philo)
{
	int	i;

	i = 0;
	while(i < philo->nb_philo)
	{
		if (pthread_create(&philo->thread, NULL, philo_life, (void *)philo) != 0)
		{
			ft_putstr_fd("\033[1;31m[Error]:\033[0;m ", 2);
			ft_putstr_fd("Error while creating thread\n", 2);
			return ;
		}
		i++;
	}
}

int	check_info(t_philo *philo)
{
	if (philo->time_to_die <= philo->time_to_eat || philo->time_to_die <= philo->time_to_sleep)
	{
		ft_putstr_fd("\033[1;31m[Error]:\033[0;m ", 2);
		ft_putstr_fd("Time to die should be greater than time to eat and time to sleep\n", 2);
		return (1);
	}
	if (philo->nb_philo < 1 || philo->nb_philo >= 200)
	{
		ft_putstr_fd("\033[1;31m[Error]:\033[0;m ", 2);
		ft_putstr_fd("Number of philosophers should be between 1 and 200\n", 2);
		return (1);
	}
	if (philo->time_to_die < 60 || philo->time_to_eat < 60 || philo->time_to_sleep < 60)
	{
		ft_putstr_fd("\033[1;31m[Error]:\033[0;m ", 2);
		ft_putstr_fd("Time should be greater than 60\n", 2);
		return (1);
	}
    return (0);
}

int	main(int ac, char **av)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (ac < 5 || ac > 6)
		printf("\033[1;31m[Error]:\033[1;m Wrong number of arguments\n");
	else
	{
		*philo = init_philo(ac, av);
		if (check_info(philo))
			return (1);
		create_th(philo);
	}
	return (0);
}