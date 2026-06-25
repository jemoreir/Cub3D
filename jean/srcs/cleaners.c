#include "cub3d.h"

void free_cub(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->file_lines[i])
		free(cub->file_lines[i++]);
	free(cub->file_lines);
	i = 0;
	while (cub->map[i])
		free(cub->map[i++]);
	free(cub->map);
	free(cub->north_t);
	free(cub->south_t);
	free(cub->west_t);
	free(cub->east_t);
}
