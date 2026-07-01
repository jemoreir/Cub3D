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

int find_start_map(t_cub *cub)
{
	int i;

	if (!cub || !cub->file_lines)
		return (-1);
	i = 0;
	while (cub->file_lines[i])
	{
		if (is_map_line(cub->file_lines[i]) && line_has_char(cub->file_lines[i], '1'))
			return (i);
		i++;
	}
	return (-1);
}
