/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:12:17 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/19 04:07:40 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_args(int argc, char **argv, int *size)
{
	int		i;
	int		j;
	char	*args;
	char	**num;

	i = 1;
	j = 0;
	args = joinargs(argc, argv);
	num = ft_split(args, ' ');
	while (num[j])
	{
		is_int(num[j]);
		is_dup(num);
		j++;
	}
	*size = j;
	return (num);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		number;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	else
	{
		fill_stack(&stack_a, check_args(argc, argv, &number));
		if (is_sorted(stack_a))
			exit(0);
		else
		{
			if (number == 2)
				sa(&stack_a);
			sort_small(&stack_a, &stack_b, number);
		}
	}
	return (0);
}
