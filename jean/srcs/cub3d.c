#include "cub3d.h"

int main(int ac, char *av[])
{
	if (ac != 2)
		return (treat_error(T_ARG), 0);
	if (!check_extension(av[1]))
		return (1);
	t_cub cub;
	init_cub(&cub);
	char **test;
	test = file_to_array(av[1]);
	for (int i; test[i]; i++)
		printf("%s\n", test[i]);
	printf("%i", cub.count_player);
	free_cub(&cub);
	return (0);
}