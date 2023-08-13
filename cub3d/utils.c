/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:36:24 by ojamal            #+#    #+#             */
/*   Updated: 2023/08/13 13:42:55 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_printing(t_map *map)
{
	printf("%s\n", map->n_path);
	printf("%s\n", map->s_path);
	printf("%s\n", map->w_path);
	printf("%s\n", map->e_path);
	printf("%s\n", map->f_color);
	printf("%s\n", map->c_color);
	for(int i = 0; map->map_2d[i]; i++)
		printf("%s\n", map->map_2d[i]);
}