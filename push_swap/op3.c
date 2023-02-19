/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:48:54 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/19 04:14:54 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack)
{
	rot(stack);
	ft_putendl_fd("ra", 1);
}

void	rb(t_node **stack)
{
	rot(stack);
	ft_putendl_fd("rb", 1);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rot(stack_a);
	rot(stack_b);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rra(stack_b);
	ft_putendl_fd("rrr", 1);
}

void	rra(t_node **stack)
{
	rev_rot(stack);
	ft_putendl_fd("rra", 1);
}
