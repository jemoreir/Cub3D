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

int	count_lines(char *file) /*Colocar dps na libft*/
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

char	**file_to_array(char *filename) /*Colocar dps na libft*/
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

int is_config_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
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

int find_start_map(t_cub *cub)
{
	int i;

	if (!cub || !cub->file_lines)
		return (0);
	i = 0;
	while (cub->file_lines[i])
	{
		if (cub->file_lines[i][0] == '\0' || is_config_line(cub->file_lines[i]))
		{
			i++;
			continue;
		}
		if (is_map_line(cub->file_lines[i]) && has_map_content(cub->file_lines[i]))
		{
			cub->map_start = i;
			return (1);
		}	
		else
			return (treat_error(T_MAP), 0);
	}
	return (treat_error(T_MAP), 0);
}

int valid_border_map(t_cub *cub)
{
	int	i;

	i = 0;
	if (!cub || !cub->map || !cub->map[0])
		return (0);
	while (cub->map[i])
		i++;
	i--;
	if (is_border_wall_line(cub->map[0]) && is_border_wall_line(cub->map[i]))
		return (1);
	return (0);
}
