/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:45:00 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/22 08:46:06 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	c_floodfill(int x, int y, char **map)
{
	if (map[y][x] != '0' && map[y][x] != 'C'
		&& map[y][x] != 'P')
		return ;
	map[y][x] = 'F';
	c_floodfill(x + 1, y, map);
	c_floodfill(x, y + 1, map);
	c_floodfill(x, y - 1, map);
	c_floodfill(x - 1, y, map);
	return ;
}

void	e_floodfill(int x, int y, char **map)
{
	if (map[y][x] != '0' && map[y][x] != 'E'
		&& map[y][x] != 'F')
		return ;
	map[y][x] = 'I';
	e_floodfill(x + 1, y, map);
	e_floodfill(x, y + 1, map);
	e_floodfill(x, y - 1, map);
	e_floodfill(x - 1, y, map);
	return ;
}

int	check_path(t_map *map, char c)
{
	int	y;
	int	x;

	y = 0;
	while (map->line->map_dup[y])
	{
		x = 0;
		while (map->line->map_dup[y][x])
		{
			if (map->line->map_dup[y][x] == c)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	flood_test(t_map *map)
{
	c_floodfill(map->x, map->y, map->line->map_dup);
	if (check_path(map, 'C') == 1)
		msg_er("Player can't reach all the collectibles");
	e_floodfill(map->x, map->y, map->line->map_dup);
	if (check_path(map, 'E') == 1)
		msg_er("Player can't reach the exit");
}

int	path(t_map *map)
{
	map->y = 0;
	while (map->line->map_dup[map->y])
	{
		map->x = 0;
		while (map->line->map_dup[map->y][map->x])
		{
			if (map->line->map_dup[map->y][map->x] == 'P')
			{
				flood_test(map);
				return (1);
			}
			map->x++;
		}
		map->y++;
	}
	return (0);
}
