/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:39:24 by ojamal            #+#    #+#             */
/*   Updated: 2023/04/29 17:34:11 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_to_die(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		pthread_mutex_lock(&philo->incr);
		if (philo->nb_meals != -1 && philo->nb_meals
			* philo->nb_philo == philo->meals)
			return (0);
		pthread_mutex_unlock(&philo->incr);
		pthread_mutex_lock(&philo->incr);
		while (i < philo->nb_philo)
		{
			if (curr_time()
				- philo->last_time_eat[philo->id] >= philo->time_to_die)
			{
				pthread_mutex_lock(&philo->write);
				printf("%ldms philo %d is dead\n", curr_time()
					- philo->start_time, philo->id + 1);
				return (1);
			}
			i++;
		}
		pthread_mutex_unlock(&philo->incr);
	}
	return (0);
}

void	philo_activities(t_philo *philo, pthread_mutex_t *right,
		pthread_mutex_t *left, int id)
{
	pthread_mutex_lock(right);
	pthread_mutex_lock(&philo->write);
	printf("%ldms philo %d has taken a fork\n", curr_time() - philo->start_time,
		id + 1);
	pthread_mutex_unlock(&philo->write);
	pthread_mutex_lock(left);
	pthread_mutex_lock(&philo->write);
	printf("%ldms philo %d has taken a fork\n", curr_time() - philo->start_time,
		id + 1);
	pthread_mutex_unlock(&philo->write);
	pthread_mutex_lock(&philo->write);
	printf("%ldms philo %d is eating\n", curr_time() - philo->start_time, id
		+ 1);
	pthread_mutex_unlock(&philo->write);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_lock(&philo->incr);
	philo->last_time_eat[id] = curr_time();
	pthread_mutex_unlock(&philo->incr);
	pthread_mutex_lock(&philo->incr);
	philo->meals++;
	pthread_mutex_unlock(&philo->incr);
	pthread_mutex_unlock(right);
	pthread_mutex_unlock(left);
}

void	*philo_life(void *arg)
{
	t_philo			*philo;
	int				id;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;

	philo = (t_philo *)arg;
	right = philo->forks + (philo->id % philo->nb_philo);
	left = philo->forks + ((philo->id + 1) % philo->nb_philo);
	pthread_mutex_lock(&philo->incr);
	id = philo->id;
	pthread_mutex_unlock(&philo->incr);
	while (1)
	{
		philo_activities(philo, right, left, id);
		pthread_mutex_lock(&philo->write);
		printf("%ldms philo %d is sleeping\n", curr_time() - philo->start_time,
			id + 1);
		pthread_mutex_unlock(&philo->write);
		ft_usleep(philo->time_to_sleep);
		pthread_mutex_lock(&philo->write);
		printf("%ldms philo %d is thinking\n", curr_time() - philo->start_time,
			id + 1);
		pthread_mutex_unlock(&philo->write);
	}
}

int	create_th(t_philo *philo)
{
	int	i;

	i = 0;
	philo->last_time_eat = malloc(sizeof(int *) * philo->nb_philo);
	philo->thread = malloc(sizeof(pthread_t) * philo->nb_philo);
	while (i < philo->nb_philo)
	{
		pthread_mutex_lock(&philo->incr);
		philo->id = i;
		philo->last_time_eat[i] = curr_time();
		pthread_mutex_unlock(&philo->incr);
		if (pthread_create(&philo->thread[i], NULL, &philo_life, philo))
			return (msg_er("Error while creating thread\n"));
		usleep(100);
		i++;
	}
	return (time_to_die(philo));
}

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (ac < 5 || ac > 6)
		return (msg_er("Wrong number of arguments\n"));
	if (init_args(ac, av, philo))
		return (1);
	if (init_philo(philo))
		return (1);
	if (create_th(philo))
		return (1);
}
