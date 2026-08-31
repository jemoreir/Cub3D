#include "cub3d.h"
#include <math.h>

static void	init_ray(t_cub *cub, int x)
{
	t_ray	*ray;

	ray = &cub->game.ray;
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = cub->game.player.dir_x
		+ cub->game.player.plane_x * ray->camera_x;
	ray->ray_dir_y = cub->game.player.dir_y
		+ cub->game.player.plane_y * ray->camera_x;
	ray->map_x = (int)cub->game.player.pos_x;
	ray->map_y = (int)cub->game.player.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

static void	perform_dda(t_cub *cub)
{
	t_ray	*ray;

	ray = &cub->game.ray;
	while (cub->map.grid[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
}

static void	calculate_wall(t_cub *cub)
{
	t_ray	*ray;

	ray = &cub->game.ray;
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x
			- ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y
			- ray->delta_dist_y;
	if (ray->perp_wall_dist < 0.01)
		ray->perp_wall_dist = 0.01;
	set_wall_limits(ray);
}

void	cast_ray(t_cub *cub, int x)
{
	init_ray(cub, x);
	init_steps(cub);
	perform_dda(cub);
	calculate_wall(cub);
}