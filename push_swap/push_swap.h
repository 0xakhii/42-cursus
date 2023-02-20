/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:12:26 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/20 01:54:51 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

void	msg_er(void);
void	is_int(char *str);
char	*joinargs(int argc, char **argv);
void	is_dup(char **num);
void	fill_stack(t_node **stack, char **num);
int		is_sorted(t_node *stack);
void	sa(t_node **stack);
void	ra(t_node **stack);
void	rra(t_node **stack);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	rb(t_node **stack);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	rrb(t_node **stack);
void	ss(t_node **stack_a, t_node **stack_b);
void	swap(t_node **stack);
void	rev(t_node **stack);
void	rot(t_node **stack);
void	push(t_node **stack_a, t_node **stack_b);
void	rev_rot(t_node **stack);
int		find_min(t_node *stack);
void	move_to_top(t_node **stack, int nb);
void	sort(t_node **stack, t_node **tmp, int size);
int		find_big(t_node *stack);
void	sort_big(t_node **stack_a, t_node **stack_b);
int		*sort_tab(t_node *stack);
#endif