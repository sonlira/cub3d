/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:08:50 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/05 18:10:39 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_pixel(t_img *img, int x, int y, int rgb)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8)); // 1 byte == 8 bits
	*(unsigned int *)dst = rgb;
}

static void	draw_background(t_app *app)
{
	int	y;
	int	x;
	int	rgb;

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

void	window_init(t_app *app)
{
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, W, H, WIN_TITLE);
	app->frame.img = mlx_new_image(app->mlx, W, H);
	app->frame.addr = mlx_get_data_addr(app->frame.img, &app->frame.bpp,
			&app->frame.line_len, &app->frame.endian);
	draw_background(app);
	mlx_put_image_to_window(app->mlx, app->win, app->frame.img, 0, 0);
}
