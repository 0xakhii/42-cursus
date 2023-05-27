/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:29:33 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/27 23:10:43 by ojamal           ###   ########.fr       */
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

t_tokens	*create_token(char *val, int type)
{
	t_tokens	*node;

	node = malloc(sizeof(t_tokens));
	node->val = val;
	node->types = type;
	node->next = NULL;
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