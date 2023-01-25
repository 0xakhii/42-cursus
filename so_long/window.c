/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:26:11 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/25 08:03:56 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_floor(t_map *map)
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

void	init_window(t_map *map)
{
	map->count = 0;
	map->collectible = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->line->width * 50,
			map->line->height * 50, "so_long");
	show_floor(map);
	show_map(map);
	mlx_hook(map->win, 2, 1L << 0, move_player, map);
	mlx_hook(map->win, 17, 1L << 17, (void *)exit, map);
	mlx_loop(map->mlx);
}

