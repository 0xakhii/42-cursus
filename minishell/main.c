/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:42:56 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/27 21:59:57 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*add_characthers(char *str, char x)
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
		new_str = malloc(ft_strlen(str) + 2);
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

t_list	*lexer_init(char *in)
{
	int		i;
	char	*str;
	t_list	*lexer;

	lexer = NULL;
	i = 0;
	while (1)
	{
		if (in[i] == '\0' || in[i] == '\n')
			break ;
		while (in[i])
		{
			str = NULL;
			if (ft_isalpha(in[i]) || in[i] == ' ' || in[i] == '\t')
			{
				while (in[i] && (ft_isalpha(in[i]) || in[i] == ' '
						|| in[i] == '\t'))
				{
					str = add_characthers(str, in[i]);
					i++;
				}
				ft_lstadd_back(&lexer, ft_lstnew(str));
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
					}
					else
					{
						str = malloc(2);
						str[0] = '<';
						str[1] = '\0';
						i++;
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
					}
					else
					{
						str = malloc(2);
						str[0] = '>';
						str[1] = '\0';
						i++;
					}
				}
				else if (in[i] == '|')
				{
					str = malloc(2);
					str[0] = '|';
					str[1] = '\0';
					i++;
				}
				else
				{
					str = malloc(2);
					str[0] = in[i];
					str[1] = '\0';
					i++;
				}
				ft_lstadd_back(&lexer, ft_lstnew(str));
			}
		}
	}
	return (lexer);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	t_list	*lexer;
	char	*in;

	lexer = NULL;
	while (1)
	{
		in = readline("minishell$>");
		if (in)
			add_history(in);
		lexer = lexer_init(in);
		quote_check(lexer);
		printing(lexer);
	}
}
