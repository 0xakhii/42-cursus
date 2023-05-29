/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:17:20 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/28 21:24:11 by ojamal           ###   ########.fr       */
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

void	quote_check(t_tokens *lexer)
{
	t_quote	*stack_single;
	t_quote	*stack_double;
	t_quote	*quotes;
	char	*str;
	size_t	i;

	quotes = malloc(sizeof(t_quote));
	stack_single = NULL;
	stack_double = NULL;
	quotes->within_double_quotes = 0;
	quotes->within_single_quotes = 0;
	while (lexer != NULL)
	{
		str = (char *)lexer->val;
		i = 0;
		while (str[i] != '\0')
		{
			if (quotes->within_single_quotes == 0 && str[i] == '\"')
			{
				if (stack_double == NULL)
				{
					push_quote(&stack_double, '\"');
					quotes->within_double_quotes = !quotes->within_double_quotes;
				}
				else
				{
					pop_quote(&stack_double);
					quotes->within_double_quotes = !quotes->within_double_quotes;
				}
			}
			else if (quotes->within_double_quotes == 0 && str[i] == '\'')
			{
				if (stack_single == NULL)
				{
					push_quote(&stack_single, '\'');
					quotes->within_single_quotes = !quotes->within_single_quotes;
				}
				else
				{
					pop_quote(&stack_single);
					quotes->within_single_quotes = !quotes->within_single_quotes;
				}
			}
			i++;
		}
		lexer = lexer->next;
	}
	if (stack_single != NULL)
	{
		printf("Unclosed single quote: %c\n", stack_single->quote);
		pop_quote(&stack_single);
	}
	if (stack_double != NULL)
	{
		printf("Unclosed double quote: %c\n", stack_double->quote);
		pop_quote(&stack_double);
	}
}

void	syntax_check(t_tokens *lexer)
{
	while (lexer)
	{
		if (lexer->types != 1 && lexer->next && lexer->next->types == 0)
			printf("syntax error near unexpected token `|'\n");
		lexer = lexer->next;
	}
}