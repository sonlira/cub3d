/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_dda.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:53:52 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/11/25 13:53:52 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_dda(t_player *player, t_game *game)
{
	t_dda	*dda;

	dda = &player->dda;
	dda->x = (int) player->x / PIXELS;
	dda->y = (int) player->y / PIXELS;
	dda->ray_angle = player->angle - (PI / 6);
	dda->x_linelength = fabs(1 / cos(dda->ray_angle));
	dda->y_linelength = fabs(1 / sin(dda->ray_angle));
	if (cos(dda->ray_angle) < 0)
		dda->x_step = -1;
	else
		dda->x_step = 1;
	if (sin(dda->ray_angle) < 0)
		dda->y_step = -1;
	else
		dda->y_step = 1;
	if (dda->x_step == -1)
		dda->x_dist = (player->x / PIXELS - dda->x) * dda->x_linelength;
	else
		dda->x_dist = (dda->x + 1 - player->x / PIXELS) * dda->x_linelength;
	if (dda->y_step == -1)
		dda->y_dist = (player->y / PIXELS - dda->y) * dda->y_linelength;
	else
		dda->y_dist = (dda->y + 1 - player->y / PIXELS) * dda->y_linelength;
	dda->pl = player;
	dda->game = game;
}

t_img	*choose_texture(t_dda *dda, t_game *g)
{
	if (dda->wall_face == 1) //horizontal wall
	{
		if (dda->y_step > 0)
		return (&g->n);
		else
		return (&g->s);
	}
	else // vertical wall
	{
		if (dda->x_step > 0)
			return (&g->e);
		else
			return (&g->w);
	}
}

void	check_wall_hit(t_dda *dda)
{
	double	true_distance;
	double	wall_hit;

	true_distance = dda->distance / cos(dda->pl->angle - dda->ray_angle);
	if (dda->wall_face == 1)
	wall_hit = dda->pl->x + true_distance * sin(dda->ray_angle);
	else
	wall_hit = dda->pl->y + true_distance * cos(dda->ray_angle);
	wall_hit /= 64.0;
	wall_hit -= floor(wall_hit);
	dda->tex_x = wall_hit * PIXELS;
	if (dda->wall_face == 0 && dda->ray_angle > PI / 2 && dda->ray_angle < 3 * PI / 2)
	dda->tex_x = PIXELS - dda->tex_x - 1;
	if (dda->wall_face == 1 && dda->ray_angle > 0 && dda->ray_angle < PI)
	dda->tex_x = PIXELS - dda->tex_x - 1;
}

// static int get_pixel_color(t_img *img, int x, int y)
// {
//     char    *dst = NULL;
//     unsigned char r, g, b;

//     // Aseguramos que no nos salimos de la textura
//     if (x < 0 || x >= img->line_len / (img->bpp / 8))
//         return (0);
//     if (y < 0)
//         return (0);

//     dst = img->addr + (y * img->line_len + x * (img->bpp / 8));

//     // MiniLibX suele almacenar en BGRA (Blue, Green, Red, Alpha)
//     b = dst[0];
//     g = dst[1];
//     r = dst[2];
//     // dst[3] sería el canal alpha si lo usas

//     return ((r << 16) | (g << 8) | b);
// }


void	calculate_wall_heigth_and_draw(t_dda *dda, t_img *text)
{
	int		wall_height;
	int		start_y;
	int		end_y;
	int		j;
	char	*dst;
    int		color;
	
	wall_height = (1.0 / dda->distance) * W;
	start_y = (H / 2) - (wall_height / 2); // top of the wall
	end_y = start_y + wall_height;
	j = start_y;
	while (j < end_y)
	{
		if (j >= 0 && j < H)
		{
			// Compute y coordinate in texture
			dda->tex_y = (int)((j - start_y) * ((double)PIXELS / wall_height));
			// Get color from texture
			dst = text->addr + (dda->tex_y * text->line_len + dda->tex_x * (text->bpp / 8));
			color = *(unsigned int *)dst;
			put_pixel(&dda->game->app->frame, dda->i, j, color);
			// printf("tex_y = %i %i %i\n\n", dda->i, j, color);
			// color = get_pixel_color(text, dda->tex_x, dda->tex_y);
			// put_pixel(&dda->game->app->frame, dda->i, j, color);
		}
		j++;
	}
}
