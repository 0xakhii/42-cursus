/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:29:01 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/21 10:22:58 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_node **stack)
{
	swap(stack);
}

void	sb(t_node **stack)
{
	swap(stack);
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
