/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 09:36:23 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/19 09:44:42 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big(t_node *stack)
{
	int		max;
	t_node	*tmp;
	int	i;

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
