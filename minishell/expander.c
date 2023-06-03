/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:07:55 by ojamal            #+#    #+#             */
/*   Updated: 2023/06/03 22:28:16 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_node	*helper(t_helper *help, char **env)
{
	t_env_node	*head;
	t_env_node	*tail;
	t_env_node	*new_node;

	head = NULL;
	tail = NULL;
	help->key_len = help->equal_sign - env[help->i];
	new_node = malloc(sizeof(t_env_node));
	new_node->key = malloc(help->key_len + 1);
	ft_strncpy(new_node->key, env[help->i], help->key_len);
	new_node->key[help->key_len] = '\0';
	help->value_start = help->equal_sign + 1;
	new_node->value = ft_strdup(help->value_start);
	new_node->next = NULL;
	if (head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		tail->next = new_node;
		tail = new_node;
	}
	return (head);
}

t_env_node	*create_env_list(char **env)
{
	t_helper	*help;
	t_env_node	*head;

	help = malloc(sizeof(t_helper));
	head = NULL;
	help->i = 0;
	while (env[help->i] != NULL)
	{
		help->equal_sign = ft_strchr(env[help->i], '=');
		if (help->equal_sign != NULL)
			head = helper(help, env);
		help->i++;
	}
	return (head);
}

t_tokens	*expand_command(t_tokens *lexer, t_env_node *env_list)
{
	t_tokens	*current_token;
	t_env_node	*env_node;
	char		*token_value;
	char		*env_name;
	bool		in_single_quotes;
	t_tokens	*quote_token;

	current_token = lexer;
	while (current_token)
	{
		token_value = current_token->val;
		if (token_value && token_value[0] == '$')
		{
			env_name = token_value + 1;
			env_node = env_list;
			in_single_quotes = false;
			quote_token = lexer;
			while (quote_token != current_token)
			{
				if (quote_token->val[0] == '\'' && quote_token->types == T_STR)
				{
					in_single_quotes = !in_single_quotes;
				}
				quote_token = quote_token->next;
			}
			if (!in_single_quotes)
			{
				while (env_node != NULL)
				{
					if (ft_strcmp(env_node->key, env_name) == 0)
					{
						free(current_token->val);
						current_token->val = ft_strdup(env_node->value);
						break ;
					}
					env_node = env_node->next;
				}
			}
		}
		current_token = current_token->next;
	}
	return (lexer);
}
