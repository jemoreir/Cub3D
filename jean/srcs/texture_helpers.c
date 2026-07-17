#include "cub3d.h"

t_config_id define_config_id(char *line)
{
	int	i;

	i = 0;
	if (!line || !is_config_line(line))
		return (T_INVALID);
	while (ft_is_space(line[i]))
		i++;
	if (line[i + 1] == 'O')
	{
		if (line[i] == 'N')
			return (T_NO);
		else if (line[i] == 'S')
			return (T_SO);
	}
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (T_WE);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (T_EA);
	else if (line[i] == 'F')
		return (T_F);
	else if (line[i] == 'C')
		return (T_C);
	return (T_INVALID);
}

int find_start_path(char *line)
{
	int	i;

	if (!line || !line[0])
		return (-1);
	i = 0;
	while (ft_is_space(line[i]))
		i++;
	if (line[i] == 'F' || line[i] == 'C')
		i++;
	else
		i += 2;
	while (ft_is_space(line[i]))
		i++;
	if (!line[i])
		return (-1);
	return (i);
}

int	define_path_textures(char *line, t_cub *cub)
{
	t_config_id	id;
	int			i;
	int			val;

	i = 0;
	val = 0;
	if (!cub || !line || !line[0])
		return (0);
	id = define_config_id(line);
	if (id == T_INVALID || id == T_F || id == T_C)
		return (0);
	if (id == T_NO)
		val = set_no(cub, line);
	else if (id == T_SO)
		val = set_so(cub, line);
	else if (id == T_WE)
		val = set_we(cub, line);
	else if (id == T_EA)
		val = set_ea(cub, line);
	if (val == 0)
		return (0);
	return (1);
}
