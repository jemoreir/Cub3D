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

int line_has_char(char *line, char c)
{
	int	i;

	if (!line || !c)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (0);
}
