/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:46:33 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/21 08:32:26 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker_bonus.h"

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	if (*stack_b)
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
}

void	rot(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp->next)
			tmp = tmp->next;
		*stack = (*stack)->next;
		tmp->next = tmp2;
		tmp2->next = NULL;
	}
}

void	rev_rot(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = *stack;
		*stack = tmp2;
	}
}

void	rrb(t_node **stack)
{
	rev_rot(stack);
	ft_putendl_fd("rrb", 1);
}
