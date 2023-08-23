/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:36:24 by ojamal            #+#    #+#             */
/*   Updated: 2023/08/22 02:37:14 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_printing(t_map *map)
{
    printf("North Path: %s\n", map->n_path);
    printf("South Path: %s\n", map->s_path);
    printf("West Path: %s\n", map->w_path);
    printf("East Path: %s\n", map->e_path);
    printf("Floor Color: %s\n", map->f_color);
    printf("Ceiling Color: %s\n", map->c_color);
    for (int i = 0; map->map_2d[i]; i++)
        printf("Map Line %d: %s\n", i, map->map_2d[i]);
}