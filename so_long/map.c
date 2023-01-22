/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:37:29 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/22 01:25:27 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *map_name)
{
	int	index;

	index = 0;
	while (map_name[index] != '\0')
		index++;
	while (map_name[index] != '.')
		index--;
	if (map_name[index + 1] != 'b' || map_name[index + 2] != 'e'
		|| map_name[index + 3] != 'r' || map_name[index + 4] != '\0')
		msg_er("Invalid map, please use a .ber file\n");
}

void	check_lines(char *line)
{
	int	index;

	index = 0;
	while (line[index] != '\0' && line[index] != '\n')
	{
		if (line[index] != '1' && line[index] != '0'
			&& line[index] != 'C' && line[index] != 'E' && line[index] != 'P')
			msg_er("Invalid map, please use only 1, 0, C, E, P\n");
		index++;
	}
}

void	check_char(char *line)
{
	int	index;
	int	c;
	int	e;
	int	p;

	index = 0;
	c = 0;
	e = 0;
	p = 0;
	while (line[index] != '\0')
	{
		if (line[index] == 'C')
			c++;
		if (line[index] == 'E')
			e++;
		if (line[index] == 'P')
			p++;
		index++;
	}
	if (e != 1)
		msg_er("Invalid map, please use only one 'E'\n");
	if (p != 1)
		msg_er("Invalid map, please use only one 'P'\n");
	if (c == 0)
		msg_er("Invalid map, please use at least one 'C'\n");
}

void	check_walls(char **map)
{
	int	index;
	int	lenght;
	int	i;
	int	j;

	index = 0;
	lenght = 0;
	i = 0;
	j = 0;
	while (map[index] != '\0')
	{
		if (lenght == 0)
			lenght = f_strlen(map[index]);
		else if (lenght != f_strlen(map[index]))
			msg_er("Invalid map, please use a rectangle map\n");
		if (map[index][0] != '1' || map[index][lenght - 1] != '1')
			msg_er("Invalid map, please use a closed map\n");
		index++;
	}
	while (map[0][i] != '\0')
		if (map[0][i++] != '1')
			msg_er("Invalid map, please use a closed map\n");
	while (map[index - 1][j] != '\0')
		if (map[index - 1][j++] != '1')
			msg_er("Invalid map, please use a closed map\n");
}

void	check_map(char *map_name)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	check_extension(map_name);
	line->fd = open(map_name, O_RDONLY);
	if (line->fd == -1)
		msg_er("Invalid file, please use a valid file\n");
	line->get_line = NULL;
	line->line = NULL;
	line->line = get_next_line(line->fd);
	if (line->line == NULL || line->line[0] == '\n')
		msg_er("Invalid map, please use a valid map\n");
	while (line->line)
	{
		line->get_line = f_strjoin(line->get_line, line->line);
		free(line->line);
		line->line = get_next_line(line->fd);
	}
	check_lines(line->get_line);
	check_char(line->get_line);
	line->map = ft_split(line->get_line, '\n');
	line->map_dup = ft_split(line->get_line, '\n');
	check_walls(line->map);
}
