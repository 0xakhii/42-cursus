/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 08:03:24 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/20 02:05:15 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_tab(t_node *stack_a, int *tab)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		tab[i] = stack_a->data;
		stack_a = stack_a->next;
		i++;
	}
	return (tab);
}

int	*sort_tab(t_node *stack_a)
{
	int	*tab;
	int	i;
	int	size;
	int	swap;

	i = 0;
	size = ft_lstsize((t_list *)stack_a);
	tab = malloc(sizeof(int) * ft_lstsize((t_list *)stack_a));
	tab = stack_to_tab(stack_a, tab);
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

void	big_to_up(t_node **stack_b)
{
	int	i;

	while (1)
	{
		i = find_big(*stack_b);
		if (i == 0)
			break ;
		else if (i <= ft_lstsize((t_list *)*stack_b) / 2)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	ft_norm(t_node **stack_a, t_node **stack_b, int range)
{
	int	*tab;
	int	i;

	i = 0;
	tab = sort_tab(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->data <= tab[i])
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if ((*stack_a)->data > tab[i]
			&& (*stack_a)->data <= tab[range + i])
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int	range;

	range = 0;
	if (ft_lstsize((t_list *)*stack_a) >= 6
		&& ft_lstsize((t_list *)*stack_a) <= 20)
		range = 4;
	else if (ft_lstsize((t_list *)*stack_a) <= 100)
		range = 15;
	else if (ft_lstsize((t_list *)*stack_a) <= 500)
		range = 40;
	ft_norm(stack_a, stack_b, range);
	while (*stack_b)
	{
		big_to_up(stack_b);
		pa(stack_a, stack_b);
	}
}
