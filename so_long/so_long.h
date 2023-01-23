/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:37:32 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/23 01:18:40 by ojamal           ###   ########.fr       */
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
	int		width;
	int		height;
	char	**map_dup;
}				t_line;

typedef struct s_map
{
	int		player;
	int		collectible;
	int		exit;
	t_line	*line;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		*img_wall;
	int		*img_player;
	int		*img_exit;
	int		*img_collectible;
	int		*img_ground;
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
void	get_size(t_map *map);
void	init_window(t_map *map);
void	showmap(t_map *map);
void	msg_er(char *msg);
void	msg_ok(char *msg);

#endif