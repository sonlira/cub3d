/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:22:25 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/11 17:50:27 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int rgb)
{
	char	*dst;

	if (x < 0 || x >= W || y < 0 || y >= H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = rgb;
}

void	draw_background(t_game *game)
{
	int		y;
	int		x;
	int		rgb;
	t_app	*app;

	app = game->app;
	y = 0;
	while (y < H)
	{
		if (y < (H / 2))
			rgb = app->ceil_rgb;
		else
			rgb = app->floor_rgb;
		x = 0;
		while (x < W)
		{
			put_pixel(&app->frame, x, y, rgb);
			++x;
		}
		++y;
	}
}
