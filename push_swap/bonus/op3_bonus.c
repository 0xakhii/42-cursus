/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:48:54 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/21 10:23:00 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_node **stack)
{
	rot(stack);
}

void	rb(t_node **stack)
{
	rot(stack);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rot(stack_a);
	rot(stack_b);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a);
	rra(stack_b);
}

void	rra(t_node **stack)
{
	rev_rot(stack);
}
