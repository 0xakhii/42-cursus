/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:37:27 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/22 01:37:01 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (argc == 2)
	{
		check_map(argv[1]);
		if (path(map) == 0)
			msg_er("Invalid map, please use a valid path\n");
		msg_ok("Map is valid");
	}
	else
		msg_er("Invalid number of arguments\n");
	return (0);
}
