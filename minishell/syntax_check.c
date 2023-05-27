/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:17:20 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/27 19:48:19 by ojamal           ###   ########.fr       */
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

void	quote_check(t_list *lexer)
{
	t_quote	*stack_single;
	t_quote	*stack_double;
	int		within_double_quotes;
	int		within_single_quotes;
	char	*str;
	size_t	i;

	stack_single = NULL;
	stack_double = NULL;
	within_double_quotes = 0;
	within_single_quotes = 0;
	while (lexer != NULL)
	{
		str = (char *)lexer->content;
		i = 0;
		while (str[i] != '\0')
		{
			if (within_single_quotes == 0 && str[i] == '\"')
			{
				if (stack_double == NULL)
				{
					push_quote(&stack_double, '\"');
					within_double_quotes = !within_double_quotes;
				}
				else
				{
					pop_quote(&stack_double);
					within_double_quotes = !within_double_quotes;
				}
			}
			else if (within_double_quotes == 0 && str[i] == '\'')
			{
				if (stack_single == NULL)
				{
					push_quote(&stack_single, '\'');
					within_single_quotes = !within_single_quotes;
				}
				else
				{
					pop_quote(&stack_single);
					within_single_quotes = !within_single_quotes;
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
