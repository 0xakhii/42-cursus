/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 00:45:00 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/21 19:18:19 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_floodfill(int x, int y, char **map)
{
	if (map[y][x] != '0' && map[y][x] != 'C'
		&& map[y][x] != 'P')
		return ;
	map[y][x] = 'F';
	p_floodfill(x + 1, y, map);
	p_floodfill(x, y + 1, map);
	p_floodfill(x, y - 1, map);
	p_floodfill(x - 1, y, map);
	return ;
}

void	e_floodfill(int x, int y, char **map)
{
	if (map[y][x] != '0' && map[y][x] != 'F'
		&& map[y][x] != 'E')
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
	map->y = 0;
	while (map->map_dup[map->y])
	{
		map->x = 0;
		while (map->map_dup[map->y][map->x])
		{
			if (map->map_dup[map->y][map->x] == c)
				return (1);
			map->x++;
		}
		map->y++;
	}
	return (0);
}

void	flood_test(t_map *map)
{
	p_floodfill(map->x, map->y, map->line->map_dup);
	if (check_path(map, 'C') == 1)
		msg_er("Player can't reach all the collectibles");
	e_floodfill(map->x, map->y, map->line->map_dup);
	if (check_path(map, 'E') == 1)
		msg_er("Player can't reach the exit");
}
