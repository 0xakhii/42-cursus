/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:17:20 by ojamal            #+#    #+#             */
/*   Updated: 2023/06/03 09:31:36 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	push_quote(t_quote **stack, char quote)
{
	t_quote	*new_node;

	new_node = malloc(sizeof(t_quote));
	if (new_node == NULL)
	{
		printf("Stack overflow\n");
		exit(0);
	}
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

int token_check(t_tokens *lexer)
{
    bool prev_pipe = false;

    while (lexer)
    {
        if (lexer->types == 0)  // Check if the token is a pipe symbol
        {
            if (!lexer->next || lexer->next->types != 1)
                return 1;  // Syntax error: pipe symbol at the end or followed by a non-command token

            if (!prev_pipe)
                prev_pipe = true;  // Set the flag to indicate a pipe symbol was encountered
            else
                return 1;  // Syntax error: consecutive pipe symbols
        }
        else if (lexer->types != 1)  // Check if the token is not a command
        {
            return 1;  // Syntax error: non-command token
        }
        else
        {
            prev_pipe = false;  // Reset the flag if the current token is a command
        }

        lexer = lexer->next;
    }

    return 0;  // No syntax error
}






void	syntax_check(t_tokens *lexer)
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
		printf("Unclosed single quote: %c\n", stack_single->quote);
	if (stack_double != NULL)
		printf("Unclosed double quote: %c\n", stack_double->quote);
}
