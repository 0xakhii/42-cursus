/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:31:51 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/18 22:19:35 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **stack, int data)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	new->data = data;
	new->next = *stack;
	*stack = new;
}

void	fill_stack(t_node **stack, char **num)
{
	int i;

	i = 0;
	while (num[i])
	{
		push(stack, ft_atoi(num[i]));
		i++;
	}
}
