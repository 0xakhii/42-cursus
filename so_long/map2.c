/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:45:00 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/04 08:58:17 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_height(t_map *map)
{
	int	index;

	index = 0;
	while (map->line->map[index] != 0)
		index++;
	map->height = index;
}

void	get_width(t_map *map)
{
	int	index;

	index = 0;
	while (map->line->map[0][index] != '\0')
		index++;
	map->width = index;
}

char **map_dup(char **dmap)
{
	int i;
	t_map *map = malloc(sizeof(t_map));

	i = 0;
	dmap = malloc((map->height + 1) * (sizeof(char *)));
	while (map->line->map[i])
	{
		dmap[i] = ft_strdup(map->line->map[i]);
		i++;
	}
	dmap[i] = 0;
	for(int i = 0; i < 4; i++)
		printf("%s", dmap[i]);
	return (dmap);
}
