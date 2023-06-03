/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 12:07:55 by ojamal            #+#    #+#             */
/*   Updated: 2023/06/03 12:08:23 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_node	*create_env_list(char **env)
{
	t_env_node	*head;
	t_env_node	*tail;
	int			i;
	char		*equal_sign;
	int			key_len;
	t_env_node	*new_node;
	char		*value_start;

	head = NULL;
	tail = NULL;
	i = 0;
	while (env[i] != NULL)
	{
		equal_sign = ft_strchr(env[i], '=');
		if (equal_sign != NULL)
		{
			key_len = equal_sign - env[i];
			new_node = malloc(sizeof(t_env_node));
			new_node->key = malloc(key_len + 1);
			ft_strncpy(new_node->key, env[i], key_len);
			new_node->key[key_len] = '\0';
			value_start = equal_sign + 1;
			new_node->value = ft_strdup(value_start);
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
		}
		i++;
	}
	return (head);
}

t_tokens	*expand_command(t_tokens *lexer, t_env_node *env_list)
{
	t_tokens	*current_token;
	char		*token_value;
	char		*env_name;
	t_env_node	*env_node;

	current_token = lexer;
	while (current_token != NULL)
	{
		token_value = current_token->val;
		if (token_value != NULL && token_value[0] == '$')
		{
			env_name = token_value + 1;
			env_node = env_list;
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
		current_token = current_token->next;
	}
	return (lexer);
}
