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

int is_config_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i + 1] == 'O' && (line[i] == 'N' || line[i] == 'S'))
	{
		if (!ft_is_space(line[i + 2]))
			return (0);
		return (1);
	}
	if ((line[i] == 'W' && line[i + 1] == 'E')
		|| (line[i] == 'E' && line[i + 1] == 'A'))
	{
		if (!ft_is_space(line[i + 2]))
			return (0);
		return (1);
	}
	if ((line[i] == 'F' || line[i] == 'C') && ft_is_space(line[i + 1]))
		return (1);
	return (0);
}

int line_has_char(char *line, char c)
{
	int	i;

	if (!line)
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

int is_out_of_map(int y, int x, t_map *map)
{
	int	len;

	if (y < 0 || y >= map->height)
		return (1);
	len = ft_len(map->grid[y]);
	if (x < 0 || x >= len)
		return (1);
	return (0);
}
