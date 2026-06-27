#include "cub3d.h"

int construct_array_cub(int fd, int count, char **array)
{
	int		i;
	int		len;

	i = 0;
	while (i < count)
	{
		array[i] = get_next_line(fd);
		if (!array[i])
		{
			ft_free_semi_array(array, i);
			treat_error(T_GNL);
			return (0);
		}
		len = ft_len(array[i]);
		if (len > 0 && array[i][len - 1] == '\n')
			array[i][len - 1] = '\0';
		i++;
	}
	array[i] = NULL;
	return (1);
}
