/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:31:51 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/20 01:53:28 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_node **stack, char **num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		ft_lstadd_back((t_list **)stack, ft_lstnew(ft_atoi(num[i])));
		i++;
	}
}

void	sort_five(t_node **stack, t_node **tmp)
{
	int	nb;

	nb = find_min(*stack);
	while (ft_lstsize((t_list *)*stack) > 3)
	{
		if ((*stack)->data == nb)
		{
			pb(stack, tmp);
			nb = find_min(*stack);
		}
		else
			move_to_top(stack, nb);
	}
	sort(stack, tmp, 3);
	while (*tmp)
		pa(stack, tmp);
}

int	find_big(t_node *stack)
{
	int		max;
	t_node	*tmp;
	int		i;

	tmp = stack;
	max = tmp->data;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	i = 0;
	while (stack)
	{
		if (stack->data == max)
			break ;
		stack = stack->next;
		i++;
	}
	return (i);
}

void	sort(t_node **stack, t_node **tmp, int size)
{
	if (size == 2)
		sa(stack);
	else if (size == 3)
	{
		if ((*stack)->data > (*stack)->next->data)
			sa(stack);
		if ((*stack)->data > (*stack)->next->next->data)
			rra(stack);
		if ((*stack)->next->data > (*stack)->next->next->data)
		{
			rra(stack);
			sa(stack);
		}
	}
	else if (size <= 5)
		sort_five(stack, tmp);
	else
		sort_big(stack, tmp);
}
