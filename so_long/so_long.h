/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:37:32 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/22 08:52:29 by ojamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include<mlx.h>
# include<stdlib.h>
# include<unistd.h>
# include<fcntl.h>
# include<stdio.h>

typedef struct s_line
{
	int		fd;
	char	*get_line;
	char	*line;
	char	**map;
	char	**map_dup;
}				t_line;

typedef struct s_map
{
	int		width;
	int		height;
	int		player;
	int		collectible;
	int		exit;
	t_line	*line;
	int		x;
	int		y;
}				t_map;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char	*get_next_line(int fd);
char	*get_first_line(char *next_line);
char	*get_new_line(char *str);
int		f_strlen(char *s);
char	*f_strjoin(char *s1, char *s2);
char	*f_strchr(char *s, char c);
char	*fd_read(int fd, char *line);
void	ft_putstr_fd(char *s, int fd);
t_line	*check_map(char *map_name);
int		path(t_map *map);
void	msg_er(char *msg);
void	msg_ok(char *msg);

#endif