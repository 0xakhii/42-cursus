/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:19:33 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/23 09:43:55 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
    if (map->line->map[map->y - 1][map->x] == '1')
        return ;
    if (map->line->map[map->y - 1][map->x] == 'C')
    {
        map->line->map[map->y - 1][map->x] = 'P';
        map->line->map[map->y][map->x] = '0';
        map->y--;
        map->count++;
    }
    else
    {
        map->line->map[map->y - 1][map->x] = 'P';
        map->line->map[map->y][map->x] = '0';
        map->y--;
    }
}

void	move_down(t_map *map)
{
	if (map->line->map[map->y + 1][map->x] == '1')
		return ;
	if (map->line->map[map->y + 1][map->x] == 'C')
	{
		map->line->map[map->y + 1][map->x] = 'P';
		map->line->map[map->y][map->x] = '0';
		map->y++;
		map->count++;
	}
	else
	{
		map->line->map[map->y + 1][map->x] = 'P';
		map->line->map[map->y][map->x] = '0';
		map->y++;
	}
}

void	move_right(t_map *map)
{
	if (map->line->map[map->y][map->x + 1] == '1')
		return ;
	if (map->line->map[map->y][map->x + 1] == 'C')
	{
		map->line->map[map->y][map->x + 1] = 'P';
		map->line->map[map->y][map->x] = '0';
		map->x++;
		map->count++;
	}
	else
	{
		map->line->map[map->y][map->x + 1] = 'P';
		map->line->map[map->y][map->x] = '0';
		map->x++;
	}
}

void	move_left(t_map *map)
{
	if (map->line->map[map->y][map->x - 1] == '1')
		return ;
	if (map->line->map[map->y][map->x - 1] == 'C')
	{
		map->line->map[map->y][map->x - 1] = 'P';
		map->line->map[map->y][map->x] = '0';
		map->x--;
		map->count++;
	}
	else
	{
		map->line->map[map->y][map->x - 1] = 'P';
		map->line->map[map->y][map->x] = '0';
		map->x--;
	}
}

int	move_player(int key, t_map *map)
{
	if (key == 13)
		move_up(map);
	if (key == 0)
		move_down(map);
	if (key == 2)
		move_right(map);
	if (key == 1)
		move_left(map);
	return (1);
}