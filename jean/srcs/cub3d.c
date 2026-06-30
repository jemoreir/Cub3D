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
	for (int i = 0; cub.file_lines[i]; i++)
		printf("%s\n", cub.file_lines[i]);
	printf("%i", cub.count_player);
	free_cub(&cub);
	return (0);
}