/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:37:27 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/27 10:18:33 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		check_extension(argv[1]);
		map.line = check_map(argv[1]);
		get_size(&map);
		if (path(&map) == 0)
			msg_er("Invalid map, please use a valid path\n");
		init_window(&map);
	}
	else
		msg_er("Invalid number of arguments\n");
	return (0);
}
