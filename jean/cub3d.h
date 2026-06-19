#ifndef CUB3D_H
# define CUB3d_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef enum e_error_type
{
	T_MALLOC,
	T_OPEN,
	T_EXTENSION,
	T_ARG
}   t_error_type;

int count_lines(char *file);
int check_extension(char *filename);
void treat_error(t_error_type error);

#endif