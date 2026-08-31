#include "cub3d.h"

int	set_floor(char *line, t_cub *cub)
{
	t_config	config;
	int			start;

	init_config(&config);
	start = find_start_path(line);
	if (start == -1)
		return (0);
	if (cub->has_floor > 0)
		return (treat_error(T_CONFIG), 0);
	while (line[start])
	{
		if (!ft_isdigit(line[start]) && line[start] != ',')
			return (treat_error(T_CONFIG), 0);
		if (line[start] == ',' && !check_parameters(&config, &start))
			return (0);
		if (ft_isdigit(line[start])
			&& !set_element_color_floor(cub, &config, &start, line))
			return (0);
	}
	if (config.sep != 2 || config.comp != 2 || config.has_d == 0)
		return (treat_error(T_CONFIG), 0);
	cub->has_floor++;
	return (1);
}

int	set_ceiling(char *line, t_cub *cub)
{
	t_config	config;
	int			start;

	init_config(&config);
	start = find_start_path(line);
	if (start == -1)
		return (0);
	if (cub->has_ceil > 0)
		return (treat_error(T_CONFIG), 0);
	while (line[start])
	{
		if (!ft_isdigit(line[start]) && line[start] != ',')
			return (treat_error(T_CONFIG), 0);
		if (line[start] == ',' && !check_parameters(&config, &start))
			return (0);
		if (ft_isdigit(line[start])
			&& !set_element_color_ceil(cub, &config, &start, line))
			return (0);
	}
	if (config.sep != 2 || config.comp != 2 || config.has_d == 0)
		return (treat_error(T_CONFIG), 0);
	cub->has_ceil++;
	return (1);
}

int	set_color(t_config_id id, t_cub *cub, char *line)
{
	if (id == T_C)
		return (set_ceiling(line, cub));
	else if (id == T_F)
		return (set_floor(line, cub));
	return (0);
}
