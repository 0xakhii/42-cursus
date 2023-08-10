/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:02:46 by ojamal            #+#    #+#             */
/*   Updated: 2023/08/10 21:42:18 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_diretions(t_map *map, char **str, int i)
{
	int	j;

	j = 0;
	if (!ft_strncmp(str[i], "NO", 2))
	{
		while (str[i][j++] != '.')
		map->n_path = ft_strdup(str[i] + j);
	}
	if (!ft_strncmp(str[i], "SO", 2))
	{
		while (str[i][j++] != '.')
		map->s_path = ft_strdup(str[i] + j);
	}
	if (!ft_strncmp(str[i], "WE", 2))
	{
		while (str[i][j++] != '.')
		map->w_path = ft_strdup(str[i] + j);
	}
	if (!ft_strncmp(str[i], "EA", 2))
	{
		while (str[i][j++] != '.')
		map->e_path = ft_strdup(str[i] + j);
	}
}

int	map_check(char **str, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		get_diretions(map, str, i);
		if (!ft_strncmp(str[i], "F", 1))
		{
			while(!ft_isdigit(str[i][j++]))
			map->f_color = ft_strdup(str[i] + j);
		}
		else if (!ft_strncmp(str[i], "C", 1))
		{
			while(!ft_isdigit(str[i][j++]))
			map->c_color = ft_strdup(str[i] + j);
		}
		j = 0;
		i++;
	}
	if (!map->n_path || !map->e_path || !map->s_path || !map->w_path)
		ft_putstr_fd("\033[1;31mCub3d:\033[0;0m Invalid path to textures\n", 2);
	// while(str[i][j] &&
	// 	(str[i][j] == ' ' || str[i][j] == '\t' || ft_isprint(str[i][j])))
	// {
	// 	if (str[i][j] == '\n' && str[i + 1][j] == '1')
	// 		break ;
	// 	j++;
	// }
	// if (str[i][j] && (str[i][j] != '1' || str[i][ft_strlen(str[i]) - 1] != '1'))
	// {
	// 	printf("%d------%d\n", i , j);
	// 	ft_putstr_fd("\033[1;31mCub3d:\033[0;0m Unclosed wall\n", 2);
	// 	return (1);
	// }
	// j = 0;
	// while(str[i][j])
	// {
	// 	if (str[i][j] != '1' || str[i][j] != '0' || str[i][j] != ' '
	// 		|| str[i][j] != 'N' || str[i][j] != 'E'
	// 			|| str[i][j] != 'W' || str[i][j] != 'S')
	// 	{
	// 		printf("%s\n", str[i]);
	// 		printf("%c\n", str[i][j]);
	// 		ft_putstr_fd("\033[1;31mCub3d:\033[0;0m Unvalid map\n", 2);
	// 		return (1);
	// 	}
	// 	j++;
	// }
	map_printing(map);
	return (0);
}
