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
		len = ft_len(array[i]);
		if (len > 0 && array[i][len - 1] == '\r')
			array[i][len - 1] = '\0';
		i++;
	}
	array[i] = NULL;
	return (1);
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

int is_border_wall_line(char *line)
{
	int	i;

	i = 0;
	if (!line || !line[i])
		return (0);
	if (!line_has_char(line, '1'))
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int has_map_content(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N'
			|| line[i] == 'W' || line[i] == 'S' || line[i] == 'E')
			return (1);
		i++;
	}
	return (0);
}

int valid_map_block(t_cub *cub)
{
	int	i;

	if (!cub || !cub->file_lines || cub->map_start == -1)
		return (0);
	i = cub->map_start;
	while (cub->file_lines[i])
	{
		if (!is_map_line(cub->file_lines[i])
			|| !has_map_content(cub->file_lines[i]))
			return (0);
		i++;
	}
	cub->map_end = i - 1;
	return (1);
}
