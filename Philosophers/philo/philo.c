/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 04:39:24 by ojamal            #+#    #+#             */
/*   Updated: 2023/03/05 03:34:50 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	init_philo(int ac, char **av)
{
	t_philo philo;

	philo.nb_philo = atoi(av[1]);
	philo.time_to_die = atoi(av[2]);
	philo.time_to_eat = atoi(av[3]);
	philo.time_to_sleep = atoi(av[4]);
	if (ac == 6)
		philo.nb_meals = atoi(av[5]);
	else
		philo.nb_meals = -1;
	return (philo);
}

pthread_mutex_t	*forks(t_philo *philo)
{
	pthread_mutex_t	*forks;
	int	i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	while (i < philo->nb_philo)
	{
		if (!pthread_mutex_init(&forks[i], NULL))
			printf("\033[1;31mError: Mutex init failed\033[0m\n");
		i++;
	}
	return (forks);
}

int	main(int ac, char **av)
{
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (ac < 5 || ac > 6)
		printf("\033[1;31mError: Wrong number of arguments\033[0m\n");
	else
	{
		*philo = init_philo(ac, av);
		philo->forks = forks(philo);

	}
	return (0);
}