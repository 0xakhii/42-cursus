/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:20:02 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/28 14:51:29 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_er(t_map *map)
{
	if (!map->img)
	{
		msg_er("Invalid texture\n");
	}
}

void	re_render(t_map *map, char *path)
{
	map->img = mlx_xpm_file_to_image(map->mlx, path,
			&map->line->width, &map->line->height);
	img_er(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img,
		map->x * 50, map->y * 50);
	mlx_destroy_image(map->mlx, map->img);
}

void	render_exit(t_map *map)
{
	if (map->line->c_count == 0)
	{
		re_render(map, "textures/floor.xpm");
		re_render(map, "textures/exit_3.xpm");
	}
	else if (map->collectible <= map->line->c_count)
	{
		re_render(map, "textures/floor.xpm");
		re_render(map, "textures/exit_1.xpm");
	}
	else
	{
		re_render(map, "textures/floor.xpm");
		re_render(map, "textures/exit_2.xpm");
	}
}

void	show_map(t_map *map)
{
	map->y = 0;
	while (map->line->map[map->y])
	{
		map->x = 0;
		while (map->line->map[map->y][map->x])
		{
			if (map->line->map[map->y][map->x] == 'P')
				re_render(map, "textures/player.xpm");
			if (map->line->map[map->y][map->x] == 'C')
				re_render(map, "textures/collectible.xpm");
			if (map->line->map[map->y][map->x] == 'E')
				render_exit(map);
			if (map->line->map[map->y][map->x] == '1')
				re_render(map, "textures/wall.xpm");
			if (map->line->map[map->y][map->x] == '0')
				re_render(map, "textures/floor.xpm");
			if (map->line->map[map->y][map->x] == ' ' ||
				map->line->map[map->y][map->x] == '\t')
				msg_er("Invalid map\n");
			map->x++;
		}
		map->y++;
	}
}
