/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:58:13 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/27 10:18:43 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_size(t_map *map)
{
	map->line->height = 0;
	map->line->width = 0;
	map->y = 0;
	while (map->line->map[map->y])
	{
		map->x = 0;
		while (map->line->map[map->y][map->x])
		{
			map->x++;
		}
		map->y++;
	}
	map->line->height = map->y;
	map->line->width = map->x;
}
