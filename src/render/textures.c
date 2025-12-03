/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:30:49 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/12/03 18:15:48 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_images(t_game *g)
{
	int	w;
	int	h;

	w = PIXELS;
	h = PIXELS;
	g->n.img = mlx_xpm_file_to_image(g->app->mlx, &g->cfg->textures[0][2], &w, &h);
	g->n.addr = mlx_get_data_addr(g->n.img, &g->n.bpp, &g->n.line_len,
		&g->n.endian);
	g->s.img = mlx_xpm_file_to_image(g->app->mlx, &g->cfg->textures[1][2], &w, &h);
	g->s.addr = mlx_get_data_addr(g->s.img, &g->s.bpp, &g->s.line_len,
		&g->s.endian);
	g->w.img = mlx_xpm_file_to_image(g->app->mlx, &g->cfg->textures[2][2], &w, &h);
	g->w.addr = mlx_get_data_addr(g->w.img, &g->w.bpp, &g->w.line_len,
		&g->w.endian);
	g->e.img = mlx_xpm_file_to_image(g->app->mlx, &g->cfg->textures[3][2], &w, &h);
	g->e.addr = mlx_get_data_addr(g->e.img, &g->e.bpp, &g->e.line_len,
		&g->e.endian);
}
