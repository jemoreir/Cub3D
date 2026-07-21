#include "cub3d.h"

int set_element_color_floor(t_cub *cub, t_config *c, int *i, char *line)
{
	cub->floor_rgb[c->comp] = cub->floor_rgb[c->comp] * 10 + (line[*i] - '0');
	if (cub->floor_rgb[c->comp] > 255)
			return (treat_error(T_CONFIG), 0);
	c->has_d = 1;
	(*i)++;
	return (1);
}

int set_element_color_ceil(t_cub *cub, t_config *c, int *i, char *line)
{
	cub->ceil_rgb[c->comp] = cub->ceil_rgb[c->comp] * 10 + (line[*i] - '0');
	if (cub->ceil_rgb[c->comp] > 255)
			return (treat_error(T_CONFIG), 0);
	c->has_d = 1;
	(*i)++;
	return (1);
}

int check_parameters(t_config *config, int *i)
{
	if (config->has_d == 0 || config->sep >= 2 || config->comp > 2)
		return (treat_error(T_CONFIG), 0);
	config->sep++;
	config->comp++;
	config->has_d = 0;
	(*i)++;
	return (1);
}

