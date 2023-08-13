/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 01:23:38 by ojamal            #+#    #+#             */
/*   Updated: 2023/08/13 13:38:38 by ojamal           ###   ########.fr       */
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
				ft_putstr_fd("\033[1;31mCub3d:\033[0;0m Invalid map name\n", 2);
				return (1);
			}
		}
		i++;
	}
	return (1);
}

void	read_map(int fd, t_map *map)
{
	if (fd == -1)
	{
		ft_putstr_fd("\033[1;31mCub3d:\033[0;0m Invalid file", 2);
		return ;
	}
	map->get_line = NULL;
	map->line = NULL;
	map->get_line = get_next_line(fd);
	while (map->get_line)
	{
		map->line = ft_strjoin(map->line, map->get_line);
		free(map->get_line);
		map->get_line = get_next_line(fd);
	}
	map->map = ft_split(map->line, '\n');
}

int	main(int ac, char **av)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (ac == 2)
	{
		if (check_filename(av[1]))
			return (1);
		else
		{
			
			read_map(open(av[1], O_RDONLY, 0666), map);
			map_check(map->map, map);
			map_printing(map);
		}
	}
	else
		ft_putstr_fd("\033[1;31mCub3d:\033[0;0m ./cub3d <map_path>\n", 2);
}