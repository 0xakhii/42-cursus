/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:26:11 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/26 06:03:06 by ojamal           ###   ########.fr       */
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

void	win_msg(t_map *map)
{
	map->count++;
	movements(map);
	ft_putstr_fd("\033[1;32m You Win\033[0m\n", 1);
	ft_putstr_fd("You collected all the collectibles in: ", 1);
	ft_putnbr_fd(map->count, 1);
	ft_putstr_fd(" moves\n", 1);
	exit(0);
}

void	movements(t_map *map)
{
	ft_putstr_fd("movements: ", 1);
	ft_putnbr_fd(map->count, 1);
	ft_putchar_fd('\n', 1);
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
