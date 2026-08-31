#include "cub3d.h"

int	is_border_wall_line(char *line)
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

int	has_map_content(char *line)
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

int	extract_map(t_cub *cub)
{
	int	i;
	int	map_it;

	map_it = 0;
	if (!cub || !cub->file_lines || cub->map_start == -1 || cub->map_end == -1)
		return (0);
	cub->map.height = cub->map_end - cub->map_start + 1;
	cub->map.grid = malloc(sizeof (char *) * (cub->map.height + 1));
	if (!cub->map.grid)
		return (treat_error(T_MALLOC), 0);
	i = cub->map_start;
	while (i <= cub->map_end)
	{
		cub->map.grid[map_it] = ft_strdup(cub->file_lines[i]);
		if (!cub->map.grid[map_it])
			return (treat_error(T_MALLOC), 0);
		map_it++;
		i++;
	}
	cub->map.grid[map_it] = NULL;
	return (1);
}
