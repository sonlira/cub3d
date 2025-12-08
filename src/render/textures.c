/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:30:49 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/12/07 20:26:12 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_texture_pixel(t_img *tex, int x, int y)
{
	unsigned int	*bf;

	if (x < 0 || x >= PIXELS || y < 0 || y >= PIXELS)
		return (0);
	bf = (unsigned int *)(tex->addr + (y * tex->line_len + x * (tex->bpp / 8)));
	return (*bf);
}

static void	charge_texture(void *mlx, t_img *tex, char *path)
{
	int	width;
	int	height;

	width = PIXELS;
	height = width;
	tex->img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_len,
			&tex->endian);

}

void	render_images(t_game *g)
{
	void	*mlx;

	mlx = g->app->mlx;
	charge_texture(mlx, &g->n, &g->cfg->textures[TEX_NO][2]);
	charge_texture(mlx, &g->s, &g->cfg->textures[TEX_SO][2]);
	charge_texture(mlx, &g->w, &g->cfg->textures[TEX_WE][2]);
	charge_texture(mlx, &g->e, &g->cfg->textures[TEX_EA][2]);
}
