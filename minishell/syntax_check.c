/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:17:20 by ojamal            #+#    #+#             */
/*   Updated: 2023/06/03 17:02:15 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	push_quote(t_quote **stack, char quote)
{
	t_quote	*new_node;

	new_node = malloc(sizeof(t_quote));
	new_node->quote = quote;
	new_node->next = *stack;
	*stack = new_node;
}

void	pop_quote(t_quote **stack)
{
	t_quote	*temp;

	if (*stack == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

int	token_check(t_tokens *lexer)
{
	if (lexer->types != 1)
	{
		if (lexer->types == 0)
			return (msg_er("syntax error near unexpected token `|'"));
		if (lexer->types == 2 && lexer->next && lexer->next->types != 1)
			return (msg_er("syntax error near unexpected token `newline'"));
		if (lexer->types == 3 && lexer->next && lexer->next->types != 1)
			return (msg_er("syntax error near unexpected token `newline'"));
		if (lexer->types == 4 && lexer->next && lexer->next->types != 1)
			return (msg_er("syntax error near unexpected token `newline'"));
		if (lexer->types == 5 && lexer->next && lexer->next->types != 1)
			return (msg_er("syntax error near unexpected token `newline'"));
	}
	while (lexer)
	{
		if (lexer->types == 0 && lexer->next && lexer->next->types != 1)
			return (msg_er("syntax error near unexpected token `|'"));
		if (lexer->types == 2 && lexer->next && lexer->next->types != 1)
			return (msg_er("syntax error near unexpected token `newline'"));
		if (lexer->types == 3 && lexer->next && lexer->next->types != 1)
			return (msg_er("syntax error near unexpected token `newline'"));
		if (lexer->types == 4 && lexer->next && lexer->next->types != 1)
			return (msg_er("syntax error near unexpected token `newline'"));
		if (lexer->types == 5 && lexer->next && lexer->next->types != 1)
			return (msg_er("syntax error near unexpected token `newline'"));
		lexer = lexer->next;
	}
	return (0);
}

int	syntax_check(t_tokens *lexer)
{
	t_quote	*stack_single;
	t_quote	*stack_double;
	char	*str;
	size_t	i;

	stack_single = NULL;
	stack_double = NULL;
	while (lexer)
	{
		str = (char *)lexer->val;
		if (str != NULL)
		{
			i = 0;
			while (str[i] != '\0')
			{
				if (str[i] == '\"')
				{
					if (stack_single == NULL || stack_single->quote != '\'')
					{
						if (stack_double == NULL || stack_double->quote == '\'')
							push_quote(&stack_double, '\"');
						else
							pop_quote(&stack_double);
					}
				}
				else if (str[i] == '\'')
				{
					if (stack_double == NULL || stack_double->quote != '\"')
					{
						if (stack_single == NULL || stack_single->quote == '\"')
							push_quote(&stack_single, '\'');
						else
							pop_quote(&stack_single);
					}
				}
				i++;
			}
		}
		lexer = lexer->next;
	}
	if (stack_single != NULL)
		return (msg_er("Unclosed single quote: \'\n"));
	if (stack_double != NULL)
		return (msg_er("Unclosed double quote: \"\n"));
	return (0);
}
