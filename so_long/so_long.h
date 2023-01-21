/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:37:32 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/21 19:20:09 by ojamal           ###   ########.fr       */
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
	char	**map_dup;
	int		x;
	int		y;
}				t_map;

typedef struct s_player
{
	int		p_x;
	int		p_y;
}				t_player;

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
void	check_map(char *map);
void	flood_test(t_map *map);
void	msg_er(char *msg);
void	msg_ok(char *msg);

#endif