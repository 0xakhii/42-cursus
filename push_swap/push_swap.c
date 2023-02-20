/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:12:17 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/20 02:44:57 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_args(int argc, char **argv, int *size)
{
	int		j;
	char	*args;
	char	**num;

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
	free(args);
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
			sort(&stack_a, &stack_b, number);
	}
	return (0);
}
