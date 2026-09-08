#include "cub3d.h"

int	init_game(t_cub *cub)
{
	init_bzero_game(&cub->game);
	cub->game.mlx = mlx_init();
	if (!cub->game.mlx)
	{
		free_game(&cub->game);
		return (treat_error(T_MALLOC), 0);
	}
	if (!init_image(cub) || !load_textures(cub))
	{
		free_game(&cub->game);
		return (0);
	}
	cub->game.win = mlx_new_window(cub->game.mlx,
			WIDTH, HEIGHT, "cub3D");
	if (!cub->game.win)
	{
		free_game(&cub->game);
		return (0);
	}
	init_player(cub);
	return (1);
}

void	close_game(t_cub *cub)
{
	if (!cub)
		return ;
	destroy_textures(cub);
	if (cub->game.img.img)
		mlx_destroy_image(cub->game.mlx, cub->game.img.img);
	if (cub->game.win)
		mlx_destroy_window(cub->game.mlx, cub->game.win);
	if (cub->game.mlx)
	{
		mlx_destroy_display(cub->game.mlx);
		free(cub->game.mlx);
	}
	free_cub(cub);
	exit(0);
}

int	key_hook(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		close_game(cub);
	if (keycode == 119)
		cub->game.key_w = 1;
	if (keycode == 115)
		cub->game.key_s = 1;
	if (keycode == 97)
		cub->game.key_a = 1;
	if (keycode == 100)
		cub->game.key_d = 1;
	if (keycode == 65361)
		cub->game.key_left = 1;
	if (keycode == 65363)
		cub->game.key_right = 1;
	return (0);
}

int	key_release(int keycode, t_cub *cub)
{
	if (keycode == 119)
		cub->game.key_w = 0;
	if (keycode == 115)
		cub->game.key_s = 0;
	if (keycode == 97)
		cub->game.key_a = 0;
	if (keycode == 100)
		cub->game.key_d = 0;
	if (keycode == 65361)
		cub->game.key_left = 0;
	if (keycode == 65363)
		cub->game.key_right = 0;
	return (0);
}

int	close_hook(t_cub *cub)
{
	close_game(cub);
	return (0);
}
