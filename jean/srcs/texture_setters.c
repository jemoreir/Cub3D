#include "cub3d.h"

int	set_no(t_cub *cub, char *line)
{
	int	start;
	int	len;
	int	fd;

	start = find_start_path(line);
	if (start == -1)
		return (0);
	len = ft_len(line) - start;
	if (cub->has_no > 0)
		return (treat_error(T_CONFIG), 0);
	cub->north_t = ft_substr(line, start, len);
	if (!cub->north_t)
		return (treat_error(T_MALLOC), 0);
	fd = open(cub->north_t, O_RDONLY);
	if (fd < 0)
		return (treat_error(T_CONFIG), 0);
	close (fd);
	cub->has_no++;
	return (1);
}

int	set_so(t_cub *cub, char *line)
{
	int	start;
	int	len;
	int	fd;

	start = find_start_path(line);
	if (start == -1)
		return (0);
	len = ft_len(line) - start;
	if (cub->has_so > 0)
		return (treat_error(T_CONFIG), 0);
	cub->south_t = ft_substr(line, start, len);
	if (!cub->south_t)
		return (treat_error(T_MALLOC), 0);
	fd = open(cub->south_t, O_RDONLY);
	if (fd < 0)
		return (treat_error(T_CONFIG), 0);
	close (fd);
	cub->has_so++;
	return (1);
}

int	set_we(t_cub *cub, char *line)
{
	int	start;
	int	len;
	int	fd;

	start = find_start_path(line);
	if (start == -1)
		return (0);
	len = ft_len(line) - start;
	if (cub->has_we > 0)
		return (treat_error(T_CONFIG), 0);
	cub->west_t = ft_substr(line, start, len);
	if (!cub->west_t)
		return (treat_error(T_MALLOC), 0);
	fd = open(cub->west_t, O_RDONLY);
	if (fd < 0)
		return (treat_error(T_CONFIG), 0);
	close (fd);
	cub->has_we++;
	return (1);
}

int	set_ea(t_cub *cub, char *line)
{
	int	start;
	int	len;
	int	fd;

	start = find_start_path(line);
	if (start == -1)
		return (0);
	len = ft_len(line) - start;
	if (cub->has_ea > 0)
		return (treat_error(T_CONFIG), 0);
	cub->east_t = ft_substr(line, start, len);
	if (!cub->east_t)
		return (treat_error(T_MALLOC), 0);
	fd = open(cub->east_t, O_RDONLY);
	if (fd < 0)
		return (treat_error(T_CONFIG), 0);
	close (fd);
	cub->has_ea++;
	return (1);
}
