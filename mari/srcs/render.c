#include "cub3d.h"

void	render_background(t_cub *cub)
{
	int	x;
	int	y;
	int	ceil_color;
	int	floor_color;

	ceil_color = rgb_to_int(cub->ceil_rgb[0],
			cub->ceil_rgb[1], cub->ceil_rgb[2]);
	floor_color = rgb_to_int(cub->floor_rgb[0],
			cub->floor_rgb[1], cub->floor_rgb[2]);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel(&cub->game.img, x, y, ceil_color);
			else
				put_pixel(&cub->game.img, x, y, floor_color);
			x++;
		}
		y++;
	}
}

void	render_frame(t_cub *cub)
{
	render_background(cub);
	render_raycast(cub);
	mlx_put_image_to_window(cub->game.mlx, cub->game.win,
		cub->game.img.img, 0, 0);
}
