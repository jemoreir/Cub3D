#include "cub3d.h"

int main(int ac, char *av[])
{
	if (ac != 2)
		return (treat_error(T_ARG), 0);
	if (!check_extension(av[1]))
		return (1);
	t_cub cub;
	init_cub(&cub);
	cub.file_lines = file_to_array(av[1]);
	if (!cub.file_lines)
		return (0);
	if (!find_start_map(&cub) || !valid_map_block(&cub) || !extract_map(&cub))
		return (free_cub(&cub), 0);
	if (!find_player(&cub) || !valid_border_map(&cub) || !valid_closed_map(&cub.map))
		return (free_cub(&cub), 0);
	free_cub(&cub);
	return (0);
}
