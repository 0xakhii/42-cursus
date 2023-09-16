/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:28:31 by ojamal            #+#    #+#             */
/*   Updated: 2023/09/15 12:00:01 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_for_textures(t_map *map)
{
	if (!map->n_path)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid north texture",
				2), 1);
	if (!map->e_path)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid east texture",
				2), 1);
	if (!map->s_path)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid south texture",
				2), 1);
	if (!map->w_path)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid west texture",
				2), 1);
	return (0);
}

int	check_for_colors(t_map *map)
{
	if (!map->f_color)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid floor color", 2),
			1);
	if (!map->c_color)
		return (ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid celling color",
				2), 1);
	return (0);
}

void	map_check(t_map *map)
{
	char	**str;
	int		i;
	int		j;
	int		lines;

	i = 0;
	j = 0;
	str = map->map_2d;
	lines = 0;
	if (check_for_textures(map) || check_for_colors(map))
		return ;
	while (str[lines])
		lines++;
	while (str[0][j])
	{
		if (str[0][j] == ' ' || str[0][j] == '\t')
		{
			str[0][j] = 'x';	
			j++;
		}
		else if (str[0][j + 1] && str[0][j + 1] != '1' && str[0][j + 1] != ' ')
			return (ft_putendl_fd("\033[1;31mCub3D: \033[0mUnclosed wall", 2));
		else
			j++;
	}
	while (i < lines - 1)
	{
		j = 0;
		while (str[i][j] == ' ' || str[i][j] == '\t')
		{
			str[i][j] = 'x';
			j++;
		}
		if (str[i][j] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
			return (ft_putendl_fd("\033[1;31mCub3D: \033[0mUnclosed wall", 2));
		i++;
	}
	j = 0;
	while (str[lines - 1][j])
	{
		if (str[lines - 1][j] == ' ' || str[lines - 1][j] == '\t')
		{
			str[lines - 1][j] = 'x';
			j++;
		}	
		else if (str[lines - 1][j + 1] && str[lines - 1][j + 1] != '1'
			&& str[lines - 1][j + 1] != ' ')
			return (ft_putendl_fd("\033[1;31mCub3D: \033[0mUnclosed wall", 2));
		else
			j++;
	}
}
