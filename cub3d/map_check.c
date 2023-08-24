/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 23:28:31 by ojamal            #+#    #+#             */
/*   Updated: 2023/08/24 03:08:32 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_for_chars(char **str, int pd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(str[i])
	{
		while (str[i][j])
		{
			while (str[i][j] == ' ' || str[i][j] == '\t')
				j++;
			if ((str[i][j] != '1' || str[i][j] != '0') && pd != 1)
			{
				ft_putendl_fd("\033[1;31mCub3D: \033[0mInvalid character", 2);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;	
	}
	if (pd != 1)
	{
		if (pd == 0)
			ft_putendl_fd("\033[1;31mCub3D: \033[0mTheres no player", 2);
		else
			ft_putendl_fd("\033[1;31mCub3D: \033[0mTheres more than one player", 2);
		return (1);
	}
	return (0);
}

void    map_check(t_map *map)
{
	char    **str;
	int     i;
	int     j;
	// int     tmp;
	int		pd;
	
	str = map->map_2d;
	i = 0;
	j = 0;
	pd = 0;
	while(str[i])
	{
		while(str[i][j])
		{
			while(str[i][j] == ' ' || str[i][j] == '\t')
				j++;
			// tmp = j;
			if ((i == 0 && str[i][j] != '1')
				|| (!str[i + 1] && str[i][j] != '1'))
			{
				ft_putendl_fd("\033[1;31mCub3D: \033[0mUnclosed map", 2);
				return ;	
			}
			// else if ((j == 0 && str[i][j] != '1')
			// 	|| (!str[i][j + 1] && str[i][j] != '1')
			// 	|| (j != 0 && str[i][tmp] != '1'))
			// {
			// 	ft_putendl_fd("\033[1;31mCube3D: \033[0mUnclosed map", 2);
			// 	return ;
			// }
			if (str[i][j] == 'N' || str[i][j] == 'W'
				|| str[i][j] == 'E' || str[i][j] == 'S')
				pd = 1;
			j++;
		}
		j = 0; 
		i++;
	}
	if (check_for_chars(str, pd))
		return ;
}
