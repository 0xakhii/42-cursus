/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhi <akhi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:23:38 by ojamal            #+#    #+#             */
/*   Updated: 2023/09/07 11:43:46 by akhi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_filename(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (!ft_strcmp(&str[i], ".cub"))
				return (0);
			else
			{
				ft_putstr_fd("\033[1;31mCube3D :\033[0;0m Invalid map name\n", 2);
				return (1);
			}
		}
		i++;
	}
	return (1);
}

t_map	*read_map(int fd, t_map *map)
{
	if (fd == -1)
	{
		ft_putstr_fd("\033[1;31mCube3D:\033[0;0m Invalid file", 2);
		return NULL;
	}
	map->get_line = NULL;
	map->line = NULL;
	map->get_line = get_next_line(fd);
	if (!map->get_line)
	{
		ft_putendl_fd("\033[1;31mCube3D:\033[0;0m Invalid file", 2);
		return NULL;
	}
	while (map->get_line)
	{
		map->line = ft_strjoin(map->line, map->get_line);
		free(map->get_line);
		map->get_line = get_next_line(fd);
	}
	free(map->get_line);
	map->map = ft_split(map->line, '\n');
	free(map->line);
	return (map);
}

void	free_map(t_map **map)
{
	int i;

	i = 0;
	free((*map)->n_path);
	free((*map)->e_path);
	free((*map)->w_path);
	free((*map)->s_path);
	free((*map)->f_color);
	free((*map)->c_color);
	i = 0;
	while((*map)->map_2d[i])
		free((*map)->map_2d[i++]);
	free((*map)->map_2d);	
}

int	main(int ac, char **av)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (ac == 2)
	{
		if (check_filename(av[1]))
			return (1);
		else
		{
			map = read_map(open(av[1], O_RDONLY, 0666), map);
			if (!map)
			{
				free(map);	
				return (1);
			}
			map_fill(map->map, map);
			map_check(map);
			// map_printing(map);
		}
		free(map);
	}
	else
		ft_putstr_fd("\033[1;31mCube3D:\033[0;0m ./cub3d <map_path>\n", 2);
	return 0;
}