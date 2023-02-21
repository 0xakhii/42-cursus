/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:19:51 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/21 08:34:18 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<limits.h>
# include<fcntl.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

// get_next_line functions

char	*get_next_line(int fd);
char	*get_first_line(char *next_line);
char	*get_new_line(char *str);
int		f_strlen(char *s);
char	*f_strjoin(char *s1, char *s2);
char	*f_strchr(char *s, char c);
char	*fd_read(int fd, char *line);

// checker functions

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