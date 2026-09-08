#include "cub3d.h"

void	free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	ft_free_array(cub->file_lines);
	ft_free_array(cub->map.grid);
	free(cub->north_t);
	free(cub->south_t);
	free(cub->west_t);
	free(cub->east_t);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	ft_free_array(map->grid);
	free(map);
}

void	free_game(t_game *game)
{
	if (!game)
		return;
	if (game->north.img)
		mlx_destroy_image(game->mlx, game->north.img);
	if (game->east.img)
		mlx_destroy_image(game->mlx, game->east.img);
	if (game->south.img)
		mlx_destroy_image(game->mlx, game->south.img);
	if (game->west.img)
		mlx_destroy_image(game->mlx, game->west.img);
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
