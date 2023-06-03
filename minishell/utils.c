/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:29:33 by ojamal            #+#    #+#             */
/*   Updated: 2023/06/03 12:08:20 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printing(t_tokens *lexer)
{
	while (lexer)
	{
		printf("%s %d\n", lexer->val, lexer->types);
		lexer = lexer->next;
	}
}
void	printing2(t_env_node *lexer)
{
	while (lexer)
	{
		printf("key:%s \nvalue:%s\n", lexer->key, lexer->value);
		lexer = lexer->next;
	}
}

int	msg_er(char *str)
{
	ft_putstr_fd("\033[1;31m[Minishell]\033[0m:", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

t_tokens	*create_token(char *val, int type)
{
	t_tokens	*node;

	if (val == NULL)
	{
		node = malloc(sizeof(t_tokens));
		node->val = NULL;
		node->types = type;
		node->next = NULL;
	}
	else
	{
		node = malloc(sizeof(t_tokens));
		node->val = val;
		node->types = type;
		node->next = NULL;
	}
	return (node);
}

void	add_token(t_tokens **lexer, t_tokens *node)
{
	t_tokens	*current;

	if (*lexer == NULL)
		*lexer = node;
	else
	{
		current = *lexer;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}
