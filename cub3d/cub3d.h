#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include<mlx.h>
# include "./get_next_line/get_next_line.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_map
{
	char	*line;
	char	*get_line;
	char	**map;
}	t_map;

int	map_check(char **str);

#endif