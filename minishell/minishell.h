/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <ojamal@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:07:29 by ojamal            #+#    #+#             */
/*   Updated: 2023/05/23 23:45:49 by ojamal           ###   ########.fr       */
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

typedef struct cmd
{
	char			*cmd;
	char			**args;
}					t_cmd;

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

int					get_cmd(void);
int					check_quote(char *input);
int					ft_isquote(char c);
int					ft_isredir(char c);
int					ft_ispipe(char c);
int					ft_isand(char c);
void				get_tokens(char *input);
char				*get_prompt(void);
// t_tokens			*creat_tokens(char *val, int type);
// t_tokens			*select_token(t_lex *lexer);

#endif