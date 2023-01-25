/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 23:37:32 by ojamal            #+#    #+#             */
/*   Updated: 2023/01/25 07:59:49 by ojamal           ###   ########.fr       */
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

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_line
{
	int		fd;
	char	*get_line;
	char	*line;
	char	**map;
	int		width;
	int		height;
	char	**map_dup;
	int		c_count;
}				t_line;


typedef struct s_map
{
	int		p_y;
	int		p_x;
	int		player;
	int		collectible;
	int		exit;
	int		wall;
	int		floor;
	t_line	*line;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	void	*img;
	int		count;
	int		collectibles;
	int		key;
}				t_map;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
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
void	show_map(t_map *map);
void	show_img(t_map *map, char *path_img, char c);
void	show_player(t_map *map);
int		move_player(int key, t_map *map);
void	msg_er(char *msg);
void	msg_ok(char *msg);

#endif