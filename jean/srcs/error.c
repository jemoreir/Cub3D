#include "cub3d.h"

void treat_error(t_error_type error)
{
    if (error == T_MALLOC)
        printf("Error: malloc.\n");
    else if (error == T_OPEN)
        printf("Error: open.\n");
    else if (error == T_EXTENSION)
        printf("Error: invalid extension.\n");
	else if (error == T_ARG)
        printf("Error: invalid arguments.\n");
    else if (error == T_GNL)
		printf("Error: GNL error.\n");
    else
        printf("Error: Unknown.\n");
}
