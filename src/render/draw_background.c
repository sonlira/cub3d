/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:22:25 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/03 20:42:49 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int rgb)
{
	char	*dst;

	if (x < 0 || x >= W || y < 0 || y >= H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8)); // 1 byte == 8 bits
	*(unsigned int *)dst = rgb;
}

// void put_pixel(t_img *img, int x, int y, int rgb)
// {
//     char *dst;

//     if (x < 0 || x >= W || y < 0 || y >= H)
//         return;

//     dst = img->addr + (y * img->line_len + x * (img->bpp / 8));

//     // Descomponer 0xRRGGBB en bytes
//     unsigned char r = (rgb >> 16) & 0xFF;
//     unsigned char g = (rgb >> 8) & 0xFF;
//     unsigned char b = rgb & 0xFF;

//     dst[0] = b;
//     dst[1] = g;
//     dst[2] = r;
//     dst[3] = 0xFF; // Alpha (opaco)
// }


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
