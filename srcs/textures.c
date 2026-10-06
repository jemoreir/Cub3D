/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:49:11 by jemoreir          #+#    #+#             */
/*   Updated: 2026/10/06 18:06:20 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	load_texture(t_cub *cub, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(cub->game.mlx, path,
			&tex->width, &tex->height);
	if (!tex->img)
		return (treat_error(T_CONTENT), 0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

int	load_textures(t_cub *cub)
{
	if (!load_texture(cub, &cub->game.north, cub->north_t))
		return (0);
	if (!load_texture(cub, &cub->game.south, cub->south_t))
		return (0);
	if (!load_texture(cub, &cub->game.west, cub->west_t))
		return (0);
	if (!load_texture(cub, &cub->game.east, cub->east_t))
		return (0);
	return (1);
}

void	destroy_textures(t_cub *cub)
{
	if (cub->game.north.img)
		mlx_destroy_image(cub->game.mlx, cub->game.north.img);
	if (cub->game.south.img)
		mlx_destroy_image(cub->game.mlx, cub->game.south.img);
	if (cub->game.west.img)
		mlx_destroy_image(cub->game.mlx, cub->game.west.img);
	if (cub->game.east.img)
		mlx_destroy_image(cub->game.mlx, cub->game.east.img);
}
