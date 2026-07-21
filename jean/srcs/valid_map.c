#include "cub3d.h"

int	find_start_map(t_cub *cub)
{
	int	i;

	if (!cub || !cub->file_lines)
		return (0);
	i = 0;
	while (cub->file_lines[i])
	{
		if (cub->file_lines[i][0] == '\0' || is_config_line(cub->file_lines[i]))
		{
			i++;
			continue ;
		}
		if (is_map_line(cub->file_lines[i])
			&& has_map_content(cub->file_lines[i])
			&& line_has_char(cub->file_lines[i], '1'))
		{
			cub->map_start = i;
			return (1);
		}
		else
			return (treat_error(T_CONFIG), 0);
	}
	return (treat_error(T_CONFIG), 0);
}

int	valid_map_block(t_cub *cub)
{
	int	i;

	if (!cub || !cub->file_lines || cub->map_start == -1)
		return (0);
	i = cub->map_start;
	while (cub->file_lines[i])
	{
		if (!is_map_line(cub->file_lines[i])
			|| !has_map_content(cub->file_lines[i]))
			return (treat_error(T_MAP), 0);
		i++;
	}
	cub->map_end = i - 1;
	return (1);
}

int	valid_border_map(t_cub *cub)
{
	int	i;

	i = 0;
	if (!cub || !cub->map.grid || !cub->map.grid[0])
		return (0);
	while (cub->map.grid[i])
		i++;
	i--;
	if (is_border_wall_line(cub->map.grid[0])
		&& is_border_wall_line(cub->map.grid[i]))
		return (1);
	return (treat_error(T_MAP), 0);
}
