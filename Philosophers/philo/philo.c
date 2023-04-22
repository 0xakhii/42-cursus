/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:39:24 by ojamal            #+#    #+#             */
/*   Updated: 2023/04/22 10:59:22 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	curr_time(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	init_philo(int ac, char **av, t_philo *philo)
{
	int		i;

	i = 0;
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->meals = 0;
	if (ac == 6)
		philo->nb_meals = ft_atoi(av[5]);
	else
		philo->nb_meals = -1;
	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	philo->time = curr_time();
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL))
			return (printf("ERROR\n"));
		i++;
	}
	pthread_mutex_init(&philo->write, NULL);
	pthread_mutex_init(&philo->incr, NULL);
	philo->thread = malloc(sizeof(pthread_t) * philo->nb_philo);
	return (0);
}

void	ft_usleep(int times)
{
	int	t_zero = curr_time();
	while (curr_time() - t_zero < times)
		usleep(500);
}

int	time_to_die(t_philo *philo)
{
	long	time;

	time = curr_time();
	if (time - philo->last_time_eat >= philo->time_to_die)
		printf("%ld philo %d died\n", time - philo->time, philo->id + 1);
	return 0;
}

void	*philo_life(void *arg)
{
	t_philo	*philo;
	pthread_mutex_t *right;
	pthread_mutex_t	*left;

	philo = (t_philo *)arg;
	right = philo->forks + philo->id;
	left = philo->forks + ((philo->id + 1) % 10);
	while (1)
	{
		pthread_mutex_lock(right);
		pthread_mutex_lock(&philo->write);
		printf("%ld philo %d has taken a fork\n", curr_time() - philo->time,
			philo->id);
		pthread_mutex_unlock(&philo->write);
		pthread_mutex_lock(left);
		pthread_mutex_lock(&philo->write);
		printf("%ld philo %d has taken a fork\n", curr_time() - philo->time,
			philo->id);
		pthread_mutex_unlock(&philo->write);
		pthread_mutex_lock(&philo->write);
		printf("%ld philo %d is eating\n", curr_time() - philo->time,
			philo->id);
		pthread_mutex_unlock(&philo->write);
		ft_usleep(philo->time_to_eat);
		pthread_mutex_lock(&philo->incr);
		philo->meals++;
		pthread_mutex_unlock(&philo->incr);
		pthread_mutex_lock(&philo->incr);
		philo->last_time_eat = curr_time();
		pthread_mutex_unlock(&philo->incr);
		pthread_mutex_unlock(right);
		pthread_mutex_unlock(left);
		pthread_mutex_lock(&philo->write);
		printf("%ld philo %d is sleeping\n", curr_time() - philo->time,
			philo->id);
		pthread_mutex_unlock(&philo->write);
		ft_usleep(philo->time_to_sleep);
		printf("%ld philo %d is thinking\n", curr_time() - philo->time,
			philo->id);
	}
}

int	create_th(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		philo->id = i + 1;
		philo->last_time_eat = curr_time();
		if (pthread_create(&philo->thread[i], NULL, &philo_life, philo))
		{
			ft_putstr_fd("\033[1;31m[Error]:\033[0;m", 2);
			ft_putstr_fd("Error while creating thread\n", 2);
			return (1);
		}
		usleep(500);
		i++;
	}
	i = 0;
	while (i < philo->nb_philo)
	{
		if (pthread_join(philo->thread[i], NULL))
		{
			ft_putstr_fd("\033[1;31m[Error]:\033[0;m", 2);
			ft_putstr_fd("Error while joining thread\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_info(t_philo *philo)
{
	if (philo->nb_philo < 1 || philo->nb_philo >= 200)
	{
		ft_putstr_fd("\033[1;31m[Error]:\033[0;m ", 2);
		ft_putstr_fd("Number of philosophers should be between 1 and 200\n", 2);
		return (1);
	}
	if (philo->time_to_die < 60 || philo->time_to_eat < 60
		|| philo->time_to_sleep < 60)
	{
		ft_putstr_fd("\033[1;31m[Error]:\033[0;m ", 2);
		ft_putstr_fd("Time should be greater than 60\n", 2);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (!(philo = malloc(sizeof(t_philo))))
		return (0);
	if (ac < 5 || ac > 6)
		printf("\033[1;31m[Error]:\033[1;m Wrong number of arguments\n");
	else
	{
		init_philo(ac, av, philo);
		if (check_info(philo))
			return (1);
		if (create_th(philo))
			return (1);
	}
	return (0);
}
