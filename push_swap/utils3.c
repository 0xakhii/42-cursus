/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:40:27 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/21 10:09:26 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_min(t_node *stack)
{
	int		min;
	t_node	*tmp;

	tmp = stack;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

int	find_pos(t_node *stack, int nb)
{
	int		i;
	t_node	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->data == nb)
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i <= ft_lstsize((t_list *)stack) / 2)
		return (i);
	else
		return (i - ft_lstsize((t_list *)stack));
	return (0);
}

void	move_to_top(t_node **stack, int nb)
{
	int	pos;

	pos = find_pos(*stack, nb);
	while (0 < pos)
	{
		ra(stack);
		pos--;
	}
	while (pos < 0)
	{
		rra(stack);
		pos++;
	}
}
