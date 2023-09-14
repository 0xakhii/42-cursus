#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include<mlx.h>
# include<stdbool.h>
# include <ctype.h>
# include "./get_next_line/get_next_line.h"

// # define ESC 53
// # define W 13
// # define A 0
// # define S 1
// # define D 2

typedef struct s_map
{
	char	*line;
	char	*get_line;
	char	**map;
	char	**map_2d;
	char	*n_path;
	char	*e_path;
	char	*w_path;
	char	*s_path;
	char	*f_color;
	char	*c_color;
	int		max_line;
	int		map_len;
}	t_map;

void	map_fill(char **str, t_map *map);
void	map_check(t_map *map);
void	map_printing(t_map *map);
void	get_map(char **str, t_map *map);
void	free_str(char **str);
#endif