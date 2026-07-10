#include "cub3d.h"

void free_cub(t_cub *cub)
{
	if (!cub)
		return;
	ft_free_array(cub->file_lines);
	ft_free_array(cub->map);
	free(cub->north_t);
	free(cub->south_t);
	free(cub->west_t);
	free(cub->east_t);
}
