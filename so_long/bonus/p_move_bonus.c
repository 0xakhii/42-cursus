/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_move_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 03:19:33 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/27 10:18:16 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_map *map)
{
	if (map->line->map[map->p_y - 1][map->p_x] == '1')
		return ;
	if (map->line->map[map->p_y - 1][map->p_x] == 'E'
		&& map->line->c_count != 0)
		return ;
	if (map->line->map[map->p_y - 1][map->p_x] == 'E'
		&& map->line->c_count == 0)
		win_msg(map);
	if (map->line->map[map->p_y - 1][map->p_x] == 'C')
	{
		map->line->map[map->p_y - 1][map->p_x] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_y--;
		map->line->c_count--;
		map->collectible++;
	}
	else
	{
		map->line->map[map->p_y - 1][map->p_x] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_y--;
	}
	map->count++;
	movements(map);
}

void	move_down(t_map *map)
{
	if (map->line->map[map->p_y + 1][map->p_x] == '1')
		return ;
	if (map->line->map[map->p_y + 1][map->p_x] == 'E'
		&& map->line->c_count != 0)
		return ;
	if (map->line->map[map->p_y + 1][map->p_x] == 'E'
		&& map->line->c_count == 0)
		win_msg(map);
	if (map->line->map[map->p_y + 1][map->p_x] == 'C')
	{
		map->line->map[map->p_y + 1][map->p_x] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_y++;
		map->line->c_count--;
		map->collectible++;
	}
	else
	{
		map->line->map[map->p_y + 1][map->p_x] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_y++;
	}
	map->count++;
	movements(map);
}

void	move_right(t_map *map)
{
	if (map->line->map[map->p_y][map->p_x + 1] == '1')
		return ;
	if (map->line->map[map->p_y][map->p_x + 1] == 'E'
		&& map->line->c_count > 0)
		return ;
	if (map->line->map[map->p_y][map->p_x + 1] == 'E'
		&& map->line->c_count == 0)
		win_msg(map);
	if (map->line->map[map->p_y][map->p_x + 1] == 'C')
	{
		map->line->map[map->p_y][map->p_x + 1] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_x++;
		map->line->c_count--;
		map->collectible++;
	}
	else
	{
		map->line->map[map->p_y][map->p_x + 1] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_x++;
	}
	map->count++;
	movements(map);
}

void	move_left(t_map *map)
{
	if (map->line->map[map->p_y][map->p_x - 1] == '1')
		return ;
	if (map->line->map[map->p_y][map->p_x - 1] == 'E'
		&& map->line->c_count > 0)
		return ;
	if (map->line->map[map->p_y][map->p_x - 1] == 'E'
		&& map->line->c_count == 0)
		win_msg(map);
	if (map->line->map[map->p_y][map->p_x - 1] == 'C')
	{
		map->line->map[map->p_y][map->p_x - 1] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_x--;
		map->line->c_count--;
		map->collectible++;
	}
	else
	{
		map->line->map[map->p_y][map->p_x - 1] = 'P';
		map->line->map[map->p_y][map->p_x] = '0';
		map->p_x--;
	}
	map->count++;
	movements(map);
}

int	move_player(int key, t_map *map)
{
	map->key = key;
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
	show_map(map);
	return (0);
}
