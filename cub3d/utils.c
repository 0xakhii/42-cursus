/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:36:24 by ojamal            #+#    #+#             */
/*   Updated: 2023/09/15 12:04:52 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_printing(t_map *map)
{
	int	i;

	printf("North Path: %s\n", map->n_path);
	printf("South Path: %s\n", map->s_path);
	printf("West Path: %s\n", map->w_path);
	printf("East Path: %s\n", map->e_path);
	printf("Floor Color: %s\n", map->f_color);
	printf("Ceiling Color: %s\n", map->c_color);
	i = 0;
	while (map->map_2d[i])
	{
		if (i > 9)
			printf("Map Line %d:  %s\n", i, map->map_2d[i]);
		else
			printf("Map Line %d:   %s\n", i, map->map_2d[i]);
		i++;
	}
}

int	find_biggest_line(char **str)
{
	int	i;
	int	max;
	int	j;

	i = 0;
	max = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}

void	fill_x(int *i, int *k, t_map *map, char **str)
{
	int	j;

	while ((*i) < map->map_len)
	{
		map->map_2d[(*i) + 1] = malloc(sizeof(char) * (map->max_line + 3));
		map->map_2d[(*i) + 1][0] = 'x';
		j = 0;
		(*k) = 1;
		while (str[(*i)][j])
		{
			if (str[(*i)][j] == ' ')
				map->map_2d[(*i) + 1][(*k)] = 'x';
			else
				map->map_2d[(*i) + 1][(*k)] = str[(*i)][j];
			j++;
			(*k)++;
		}
		while ((*k) <= map->max_line + 1)
		{
			map->map_2d[(*i) + 1][(*k)] = 'x';
			(*k)++;
		}
		map->map_2d[(*i) + 1][(*k)] = '\0';
		(*i)++;
	}
}

int	map_len(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	get_map(char **str, t_map *map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	map->max_line = find_biggest_line(str);
	map->map_len = map_len(str);
	map->map_2d = (char **)malloc(sizeof(char *) * (map->map_len + 3));
	map->map_2d[0] = (char *)malloc(sizeof(char) * (map->max_line + 3));
	while (k <= map->max_line + 1)
	{
		map->map_2d[0][k] = 'x';
		k++;
	}
	map->map_2d[0][k] = '\0';
	fill_x(&i, &k, map, str);
	map->map_2d[i + 1] = (char *)malloc(sizeof(char) * (map->max_line + 3));
	k = 0;
	while (k <= map->max_line + 1)
	{
		map->map_2d[i + 1][k] = 'x';
		k++;
	}
	map->map_2d[i + 1][k] = '\0';
	map->map_2d[i + 2] = NULL;
}
