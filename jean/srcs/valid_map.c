#include "cub3d.h"

int	check_extension(char *filename)
{
	int	len;

	len = ft_len(filename);
	if (!filename || len < 5)
		return (treat_error(T_EXTENSION), 0);
	if (filename[len - 4] != '.' || filename[len - 3] != 'c' || filename[len
		- 2] != 'u' || filename[len - 1] != 'b')
		return (treat_error(T_EXTENSION), 0);
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
	int		i;
	int		count;
	char	**arr;

	count = count_lines(filename);
	fd = open(filename, O_RDONLY);
	if (count == -1 || fd < 0)
		return (treat_error(T_OPEN), NULL);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (treat_error(T_MALLOC), NULL);
	i = 0;
	while (i < count)
	{
		arr[i] = get_next_line(fd);
		if (!arr[i])
			return (treat_error(T_OPEN), NULL);
		if (arr[i][ft_len(arr[i]) - 1] == '\n')
			arr[i][ft_len(arr[i]) - 1] = '\0';
		i++;
	}
	arr[i] = NULL;
	close(fd);
	return (arr);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	if (line[i] == '\0')
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'W' && line[i] != 'S' && line[i] != 'E' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
