/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:31:51 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/21 10:26:09 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	fill_stack(t_node **stack, char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		ft_lstadd_back((t_list **)stack, ft_lstnew(ft_atoi(num[i])));
		free(num[i]);
		i++;
	}
	free(num);
}

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

int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
