/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:11:28 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/28 14:39:18 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_img(t_map *map, void *img)
{
	int	x;
	int	y;

	y = 0;
	while (map->line->map[y])
	{
		x = 0;
		while (map->line->map[y][x])
		{
			if (map->line->map[y][x] == 'C')
			{
				mlx_put_image_to_window(map->mlx, map->win, img,
					x * 50, y * 50);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	animation(t_map *map)
{
	static int	i;
	static int	frame;

	if (++frame < 4000)
		return (0);
	if (i == 0)
		map->img = mlx_xpm_file_to_image(map->mlx, "textures/collectible.xpm",
				&map->line->width, &map->line->height);
	else if (i == 1)
		map->img = mlx_xpm_file_to_image(map->mlx, "textures/collectible2.xpm",
				&map->line->width, &map->line->height);
	put_img(map, map->img);
	if (i == 2)
		i = 0;
	else
		i++;
	frame = 0;
	return (0);
}
