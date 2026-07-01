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
	cub.map_start = find_start_map(&cub);
	printf("%i\n", cub.map_start);
	free_cub(&cub);
	return (0);
}