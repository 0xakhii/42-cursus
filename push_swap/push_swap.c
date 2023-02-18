/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:12:17 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/18 22:20:55 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_args(int argc, char **argv)
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
	return (num);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		exit(0);
	else
	{
		fill_stack(&stack_a, check_args(argc, argv));
		for (int i = 0; i < argc - 1; i++)
		{
			printf("%d\n", stack_a->data);
			stack_a = stack_a->next;
		}
		
	}
	return (0);
}
