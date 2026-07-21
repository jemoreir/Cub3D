#include "cub3d.h"

int	construct_array_cub(int fd, int count, char **array)
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
		len = ft_len(array[i]);
		if (len > 0 && array[i][len - 1] == '\r')
			array[i][len - 1] = '\0';
		i++;
	}
	array[i] = NULL;
	return (1);
}

int	count_lines(char *file)
{
	char	*line;
	int		r;
	int		fd;

	fd = open(file, O_RDONLY);
	r = 0;
	if (fd < 0)
		return (treat_error(T_OPEN), -1);
	line = get_next_line(fd);
	while (line)
	{
		r++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (r);
}

char	**file_to_array(char *filename)
{
	int		fd;
	int		count;
	char	**arr;

	count = count_lines(filename);
	if (count < 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (treat_error(T_OPEN), NULL);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
	{
		close(fd);
		treat_error(T_MALLOC);
		return (NULL);
	}
	if (!construct_array_cub(fd, count, arr))
	{
		close(fd);
		return (NULL);
	}
	close(fd);
	return (arr);
}
