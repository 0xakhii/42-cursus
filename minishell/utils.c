/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:29:33 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/31 03:49:37 by ojamal           ###   ########.fr       */
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
			printf("token_value: %s\n", token_value);
			env_name = token_value + 1;
			printf("env_name: %s\n", env_name);
			env_node = env_list;
			while (env_node != NULL)
			{
				if (ft_strcmp(env_node->key, env_name) == 0)
				{
					printf("Before expansion: %s\n", current_token->val);
					free(current_token->val);
					current_token->val = ft_strdup(env_node->value);
					printf("After expansion: %s\n", current_token->val);
					break ;
				}
				env_node = env_node->next;
			}
		}
		current_token = current_token->next;
	}
	return (lexer);
}
