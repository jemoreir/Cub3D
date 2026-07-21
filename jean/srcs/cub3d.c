#include "cub3d.h"

int main(int ac, char *av[])
{
	t_cub cub;

	if (ac != 2)
		return (treat_error(T_ARG), 0);
	if (!parsing_cub(av[1], &cub))
		return (0);
	printf("// SUCESSO //\n");
	free_cub(&cub);
	return (0);
}

int parsing_cub(char *filename, t_cub *cub)
{
	if (!cub || !filename || !check_extension(filename))
		return (0);
	init_cub(cub);
	cub->file_lines = file_to_array(filename);
	if (!cub->file_lines)
		return (0);
	if (!find_start_map(cub) || !valid_map_block(cub) || !extract_map(cub))
		return (free_cub(cub), 0);
	if (!find_player(cub) || !valid_border_map(cub) || !valid_closed_map(&cub->map))
		return (free_cub(cub), 0);
	if (!valid_configs(cub))
		return (free_cub(cub), 0);
	return (1);
}