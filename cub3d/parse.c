/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 03:02:46 by ojamal            #+#    #+#             */
/*   Updated: 2023/08/10 03:52:10 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_check(char **str)
{
	int i = 0;
	int j = 0;
	while(str[i])
	{
		while(str[i][j] == ' ' || str[i][j] == '\t')
			j++;
		if (str[i][j] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
		{
			ft_putstr_fd("\033[1;31mCub3d:\033[0;0m Unclosed wall\n", 2);
			return 1;
		}
		j = 0;
		// while(str[i][j])
		// {
		// 	if (str[i][j] != '1' || str[i][j] != '0' || str[i][j] != ' '
		// 		|| str[i][j] != 'N' || str[i][j] != 'E'
		// 			|| str[i][j] != 'W' || str[i][j] != 'S')
		// 	{
		// 		printf("%s\n", str[i]);
		// 		printf("%c\n", str[i][j]);
		// 		ft_putstr_fd("\033[1;31mCub3d:\033[0;0m Unvalid map\n", 2);
		// 		return 1;
		// 	}
		// 	j++;
		// }
		i++;
	}
	return 0;
}
