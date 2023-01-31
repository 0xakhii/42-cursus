/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:12:17 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/31 19:50:14 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**args;

	i = 1;
	j = 0;
	if (argc < 2)
		exit(0);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[j])
			is_int(args[j++]);
	}
	else
	{
		while (argv[i])
			is_int(argv[i++]);
	}
	return (0);
}
