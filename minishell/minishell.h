/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:07:29 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/31 01:00:17 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cmd
{
	int			argc;
	char			**argv;
	struct s_cmd *next;
}					t_cmd;

typedef struct s_quote
{
	char			quote;
	int				within_double_quotes;
	int				within_single_quotes;
	struct s_quote	*next;
}					t_quote;

typedef struct s_tokens
{
	char			*val;
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
	struct s_tokens	*next;
}					t_tokens;

void				printing(t_tokens *lexer);
void				syntax_check(t_tokens *lexer);
void				quote_check(t_tokens *lexer);
int					get_cmd(void);
int					check_quote(char *input);
int					ft_isquote(char c);
int					ft_isredir(char c);
int					ft_ispipe(char c);
int					ft_isand(char c);
void				get_tokens(char *input);
void				pipe_check(t_tokens *lexer);
char				*get_prompt(void);
t_tokens			*create_token(char *val, int type);
void				add_token(t_tokens **lexer, t_tokens *node);
#endif