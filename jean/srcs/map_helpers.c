#include "cub3d.h"

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
