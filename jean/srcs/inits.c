#include "cub3d.h"

void init_cub(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	cub->map_start = -1;
	cub->player_x = -1;
	cub->player_y = -1;
}
