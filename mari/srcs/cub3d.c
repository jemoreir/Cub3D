#include "cub3d.h"

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		return (treat_error(T_ARG), 0);
	if (!parsing_cub(av[1], &cub))
		return (0);
	if (!init_game(&cub))
		return (free_cub(&cub), 0);
	mlx_hook(cub.game.win, 2, 1L << 0, key_hook, &cub);
	mlx_hook(cub.game.win, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.game.win, 17, 0, close_hook, &cub);
	mlx_loop_hook(cub.game.mlx, game_loop, &cub);
	mlx_loop(cub.game.mlx);
	return (0);
}

int	parsing_cub(char *filename, t_cub *cub)
{
	if (!cub || !filename || !check_extension(filename))
		return (0);
	init_cub(cub);
	cub->file_lines = file_to_array(filename);
	if (!cub->file_lines)
		return (0);
	if (!find_start_map(cub) || !valid_map_block(cub) || !extract_map(cub))
		return (free_cub(cub), 0);
	if (!find_player(cub) || !valid_border_map(cub)
		|| !valid_closed_map(&cub->map))
		return (free_cub(cub), 0);
	if (!valid_configs(cub))
		return (free_cub(cub), 0);
	return (1);
}
