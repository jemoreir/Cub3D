#include "cub3d.h"

int	init_image(t_cub *cub)
{
	cub->game.img.img = mlx_new_image(cub->game.mlx, WIDTH, HEIGHT);
	if (!cub->game.img.img)
		return (0);
	cub->game.img.addr = mlx_get_data_addr(cub->game.img.img,
			&cub->game.img.bpp,
			&cub->game.img.line_len,
			&cub->game.img.endian);
	return (1);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}
