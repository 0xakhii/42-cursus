/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:12:26 by ojamal            #+#    #+#             */
/*   Updated: 2023/02/18 22:11:21 by ojamal           ###   ########.fr       */
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

#endif