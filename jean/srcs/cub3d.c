#include "cub3d.h"

int main(int ac, char *av[])
{
	if (ac != 2)
		return (treat_error(T_ARG), 0);
	if (!check_extension(av[1]))
		return (1);
	t_cub cub;
	init_cub(&cub);
	printf("%i", cub.count_player);
	return (0);
}