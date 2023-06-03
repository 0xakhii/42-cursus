/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:42:56 by ojamal            #+#    #+#             */
/*   Updated: 2023/06/02 22:51:02 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_characters(char *str, char x)
{
	char	*new_str;
	int		i;

	i = 0;
	if (str == NULL)
	{
		new_str = malloc(2);
		new_str[0] = x;
		new_str[1] = '\0';
	}
	else
	{
		new_str = malloc(strlen(str) + 2);
		while (str[i])
		{
			new_str[i] = str[i];
			i++;
		}
		new_str[i] = x;
		new_str[i + 1] = '\0';
	}
	return (new_str);
}

t_tokens	*lexer_init(char *in)
{
	int			i;
	char		*str;
	t_tokens	*lexer;
	t_tokens	*node;

	lexer = NULL;
	i = 0;
	while (1)
	{
		if (in[i] == '\0' || in[i] == '\n')
			break ;
		while (in[i] != '\0')
		{
			str = NULL;
			if (ft_isalpha(in[i]) || in[i] == ' ' || in[i] == '\t')
			{
				while (in[i] && (ft_isalpha(in[i]) || in[i] == ' '
						|| in[i] == '\t'))
				{
					str = add_characters(str, in[i]);
					i++;
				}
				node = create_token(str, T_STR);
				add_token(&lexer, node);
			}
			else
			{
				if (in[i] == '<')
				{
					if (in[i + 1] == '<')
					{
						str = malloc(3);
						str[0] = '<';
						str[1] = '<';
						str[2] = '\0';
						i += 2;
						node = create_token(str, T_HERD);
						add_token(&lexer, node);
					}
					else
					{
						str = malloc(2);
						str[0] = '<';
						str[1] = '\0';
						i++;
						node = create_token(str, T_IN_RD);
						add_token(&lexer, node);
					}
				}
				else if (in[i] == '>')
				{
					if (in[i + 1] == '>')
					{
						str = malloc(3);
						str[0] = '>';
						str[1] = '>';
						str[2] = '\0';
						i += 2;
						node = create_token(str, T_APP);
						add_token(&lexer, node);
					}
					else
					{
						str = malloc(2);
						str[0] = '>';
						str[1] = '\0';
						i++;
						node = create_token(str, T_OUT_RD);
						add_token(&lexer, node);
					}
				}
				else if (in[i] == '|')
				{
					str = malloc(2);
					str[0] = '|';
					str[1] = '\0';
					i++;
					node = create_token(str, T_PIPE);
					add_token(&lexer, node);
				}
				else
				{
					str = malloc(2);
					str[0] = in[i];
					str[1] = '\0';
					i++;
					node = create_token(str, T_STR);
					add_token(&lexer, node);
				}
			}
		}
	}
	node = create_token(NULL, T_EOF);
	add_token(&lexer, node);
	return (lexer);
}

int	main(int ac, char **av, char **env)
{
	t_tokens	*lexer;
	t_env_node	*env_list;
	char		*in;

	(void)ac;
	(void)av;
	lexer = NULL;
	while (1)
	{
		in = readline("minishell$>");
		if (in)
			add_history(in);
		lexer = lexer_init(in);
		syntax_check(lexer);
		if (pipe_check(lexer))
			printf("Minishell: syntax error near unexpected token `|'\n");
		env_list = create_env_list(env);
		// printing2(env_list);
		expand_command(lexer, env_list);
		// printing(lexer);
	}
}
