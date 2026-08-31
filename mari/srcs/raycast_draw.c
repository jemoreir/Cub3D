#include "cub3d.h"
#include <math.h>

static t_texture	*get_wall_texture(t_cub *cub)
{
	t_ray	*ray;

	ray = &cub->game.ray;
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (&cub->game.west);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		return (&cub->game.east);
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return (&cub->game.north);
	return (&cub->game.south);
}

static int	get_texture_pixel(t_texture *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width
		|| y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + y * tex->line_len
		+ x * (tex->bpp / 8);
	return (*(unsigned int *)pixel);
}

static void	init_texture_draw(t_cub *cub, t_texdraw *d)
{
	t_ray	*ray;

	ray = &cub->game.ray;
	d->tex = get_wall_texture(cub);
	if (ray->side == 0)
		d->wall_x = cub->game.player.pos_y
			+ ray->perp_wall_dist * ray->ray_dir_y;
	else
		d->wall_x = cub->game.player.pos_x
			+ ray->perp_wall_dist * ray->ray_dir_x;
	d->wall_x -= floor(d->wall_x);
	d->tex_x = (int)(d->wall_x * d->tex->width);
	if ((ray->side == 0 && ray->ray_dir_x < 0)
		|| (ray->side == 1 && ray->ray_dir_y > 0))
		d->tex_x = d->tex->width - d->tex_x - 1;
	d->step = (double)d->tex->height / ray->line_height;
	d->tex_pos = (ray->draw_start - HEIGHT / 2
			+ ray->line_height / 2) * d->step;
}

static void	draw_textured_column(t_cub *cub, int x)
{
	t_texdraw	d;
	int			y;
	int			tex_y;

	init_texture_draw(cub, &d);
	y = cub->game.ray.draw_start;
	while (y <= cub->game.ray.draw_end)
	{
		tex_y = (int)d.tex_pos;
		if (tex_y >= d.tex->height)
			tex_y = d.tex->height - 1;
		d.tex_pos += d.step;
		put_pixel(&cub->game.img, x, y,
			get_texture_pixel(d.tex, d.tex_x, tex_y));
		y++;
	}
}

void	render_raycast(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		cast_ray(cub, x);
		draw_textured_column(cub, x);
		x++;
	}
}
