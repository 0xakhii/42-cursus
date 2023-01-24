/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:26:11 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/24 03:00:11 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_window(t_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->line->width * 50,
			map->line->height * 50, "so_long");
	showmap(map);
	mlx_hook(map->win, 2, 1L << 0, move_player, map);
	mlx_hook(map->win, 17, 1L << 17, (void *)exit, map);
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

void	put_floor(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= map->line->height)
	{
		j = 0;
		while (j <= map->line->width)
		{
			map->img = mlx_xpm_file_to_image(map->mlx, "textures/floor.xpm",
					&map->line->width, &map->line->height);
			mlx_put_image_to_window(map->mlx, map->win,
				map->img, j * map->line->width, i * map->line->height);
			j++;
		}
		i++;
	}
}

void	showmap(t_map *map)
{
	put_floor(map);
	map->y = 0;
	while (map->line->map[map->y])
	{
		map->x = 0;
		while (map->line->map[map->y][map->x])
		{
			put_img(map, "textures/floor.xpm", '0');
			put_img(map, "textures/wall.xpm", '1');
			put_img(map, "textures/exit.xpm", 'E');
			put_img(map, "textures/player.xpm", 'P');
			put_img(map, "textures/collectible.xpm", 'C');
			map->x++;
		}
		map->y++;
	}
}
