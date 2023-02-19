/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:29:01 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/19 04:32:40 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack)
{
	swap(stack);
	ft_putendl_fd("sa", 1);
}

void	sb(t_node **stack)
{
	swap(stack);
	ft_putendl_fd("sb", 1);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
}
