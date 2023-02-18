/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:12:17 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/18 05:41:18 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*args;
	char	**num;

	i = 1;
	j = 0;
	if (argc < 2)
		exit(0);
	else
	{
		args = joinargs(argc, argv);
		num = ft_split(args, ' ');
		while (num[j])
		{
			is_int(num[j]);
			is_dup(num);
			j++;
		}
	}
	return (0);
}
