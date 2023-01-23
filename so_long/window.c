/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:26:11 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/23 01:27:36 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

void	init_window(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->line->width * 50, map->line->height * 50, "so_long");
	mlx_hook(map->win, 17, 0, close_window, map);
	showmap(map);
	mlx_loop(map->mlx);
}

void	put_img(t_map *map, char *path_img, char c)
{
	map->img = mlx_xpm_file_to_image(map->mlx, path_img,
			&map->line->width, &map->line->height);
	if (map->line->map[map->y][map->x] == c)
		mlx_put_image_to_window(map->mlx, map->win,
			map->img, map->x * map->line->width, map->y * map->line->height);
	mlx_destroy_image(map->mlx, map->img);
}

void	showmap(t_map *map)
{
	map->y = 0;
	while (map->line->map[map->y])
	{
		map->x = 0;
		while (map->line->map[map->y][map->x])
		{
			put_img(map, "textures/ground.xpm", '0');
			put_img(map, "textures/wall.xpm", '1');
			map->x++;
		}
		map->y++;
	}
}