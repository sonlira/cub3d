/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:22:25 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/17 18:25:58 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int rgb)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8)); // 1 byte == 8 bits
	*(unsigned int *)dst = rgb;
}

void	draw_background(t_app *app)
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
