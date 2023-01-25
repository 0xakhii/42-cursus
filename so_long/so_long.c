/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:37:27 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/25 08:05:21 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc == 2)
	{
		map.line = check_map(argv[1]);
		get_size(&map);
		if (path(&map) == 0)
			msg_er("Invalid map, please use a valid path\n");
		msg_ok("Map is valid");
		init_window(&map);
	}
	else
		msg_er("Invalid number of arguments\n");
	return (0);
}
