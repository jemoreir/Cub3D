#include "cub3d.h"

int main(int ac, char *av[])
{
	(void) ac;
	int r;

	if (ac != 2)
		return (treat_error(T_ARG), 0);
	if (check_extension(av[1]))
		return (1);
	r = count_lines(av[1]);
	return (r);
}