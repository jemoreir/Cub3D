#include "cub3d.h"

int valid_name(char *filename)
{
	int len;

	len = ft_len(filename);
	if (!filename || len < 5)
	{
		printf("Error: Invalid File Name.");
		return (1);
	}
	if (filename[len - 4] == '.' && filename[len - 3] == 'c'
		&& filename[len - 2] == 'u' && filename[len - 1] == 'b')
		return (0);
	return (0);
}
