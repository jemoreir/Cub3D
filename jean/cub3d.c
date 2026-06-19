#include "cub3d.h"

int main(int ac, char *av[])
{
	(void) ac;
	int r;

	if (check_extension(av[1]))
		return (1);
	r = count_lines(av[1]);
	return (r);
}