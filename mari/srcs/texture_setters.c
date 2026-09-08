#include "cub3d.h"
#include <sys/stat.h>

static int	check_path(char *line)
{
	int	start;
	int	len;
	struct stat path_stat;

	start = find_start_path(line);
	if (start == -1)
		return (-1);
	len = ft_len(line);
	if (len < 5)
		return (treat_error(T_PATH), -1);
	if (line[len - 1] != 'm' || line[len - 2] != 'p'
		|| line[len - 3] != 'x' || line[len - 4] != '.')
		return (treat_error(T_EXTENSION), -1);
	if (stat(&line[start], &path_stat) || !S_ISREG(path_stat.st_mode))
		return(treat_error(T_PATH), -1);
	if (!path_stat.st_size)
		return (treat_error(T_CONTENT), -1);
	return (start);
}

int	set_no(t_cub *cub, char *line)
{
	int	start;
	int	len;
	int	fd;

	start = check_path(line);
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

	start = check_path(line);
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

	start = check_path(line);
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

	start = check_path(line);
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
