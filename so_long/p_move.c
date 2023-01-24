/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:19:33 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/24 03:19:33 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *map)
{
	if (map->line->map[map->p_y - 1][map->p_x] == '1')
		return ;
    if (map->line->map[map->p_y - 1][map->p_x] == 'C')
    {
        map->line->map[map->p_y - 1][map->p_x] = 'P';
        map->line->map[map->p_y][map->p_x] = '0';
        map->p_y--;
        map->count++;
    }
    else
    {
        map->line->map[map->p_y - 1][map->p_x] = 'P';
        map->line->map[map->p_y][map->p_x] = '0';
        map->p_y--;
    }
}

void	move_down(t_map *map)
{
	if (map->line->map[map->p_y + 1][map->p_x] == '1')
		return ;
	if (map->line->map[map->p_y + 1][map->p_x] == 'C')
	{
		map->line->map[map->p_y + 1][map->p_x] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_y++;
		map->count++;
	}
	else
	{
		map->line->map[map->p_y + 1][map->p_x] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_y++;
	}

}

void	move_right(t_map *map)
{
	if (map->line->map[map->p_y][map->p_x + 1] == '1')
		return ;
	if (map->line->map[map->p_y][map->p_x + 1] == 'C')
	{
		map->line->map[map->p_y][map->p_x + 1] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_x++;
		map->count++;
	}
	else
	{
		map->line->map[map->p_y][map->p_x + 1] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_x++;
	}

}

void	move_left(t_map *map)
{
	if (map->line->map[map->p_y][map->p_x - 1] == '1')
		return ;
	if (map->line->map[map->p_y][map->p_x - 1] == 'C')
	{
		map->line->map[map->p_y][map->p_x - 1] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_x--;
		map->count++;
	}
	else
	{
		map->line->map[map->p_y][map->p_x - 1] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_x--;
	}
}

int	move_player(int key, t_map *map)
{
	if (key == 53)
		exit(0);
	if (key == 13 || key == 126)
		move_up(map);
	if (key == 1 || key == 125)
		move_down(map);
	if (key == 2 || key == 124)
		move_right(map);
	if (key == 0 || key == 123)
		move_left(map);
	return (1);
}