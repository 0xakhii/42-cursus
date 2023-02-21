/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:29:48 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/21 10:23:56 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_input(t_node **stack_a, t_node **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b);
	else
		msg_er();
}

void	read_input(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		check_input(stack_a, stack_b, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		number;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		exit(0);
	else
	{
		fill_stack(&stack_a, check_args(argc, argv, &number));
		read_input(&stack_a, &stack_b);
	}
	if (is_sorted(stack_a) && stack_b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (0);
}
