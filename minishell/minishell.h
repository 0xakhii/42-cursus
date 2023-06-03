/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:07:29 by ojamal            #+#    #+#             */
/*   Updated: 2023/06/03 22:22:09 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cmd
{
	int					argc;
	char				**argv;
	struct s_cmd		*next;
}						t_cmd;

typedef struct s_quote
{
	char				quote;
	struct s_quote		*next;
}						t_quote;

typedef struct s_helper
{
	int key_len;
	char *equal_sign;
	char *value_start;
	int i;
}	t_helper;

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
}						t_env_node;

typedef struct s_tokens
{
	char				*val;
	enum
	{
		T_PIPE,
		T_STR,
		T_IN_RD,
		T_OUT_RD,
		T_HERD,
		T_APP,
		T_EOF
	} types;
	struct s_tokens		*next;
}						t_tokens;

void					printing(t_tokens *lexer);
t_tokens				*lexer_init(char *in);
int						msg_er(char *str);
void					printing2(t_env_node *lexer);
int						syntax_check(t_tokens *lexer);
void					quote_check(t_tokens *lexer);
int						get_cmd(void);
t_tokens				*expand_command(t_tokens *lexer, t_env_node *env_list);
t_env_node				*create_env_list(char **env);
void					get_tokens(char *input);
int						token_check(t_tokens *lexer);
char					*get_prompt(void);
t_tokens				*create_token(char *val, int type);
void					add_token(t_tokens **lexer, t_tokens *node);
#endif