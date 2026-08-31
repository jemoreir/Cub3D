#include "cub3d.h"

void	treat_error(t_error_type error)
{
	if (error == T_MALLOC)
		printf("Error: MALLOC.\n");
	else if (error == T_OPEN)
		printf("Error: OPEN.\n");
	else if (error == T_EXTENSION)
		printf("Error: INVALID EXTENSION.\n");
	else if (error == T_ARG)
		printf("Error: INVALID ARGUMENTS.\n");
	else if (error == T_GNL)
		printf("Error: GNL.\n");
	else if (error == T_MAP)
		printf("Error: MAP.\n");
	else if (error == T_CONFIG)
		printf("Error: CONFIG.\n");
}
