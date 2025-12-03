/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:25:32 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/12/03 20:38:19 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_front(t_dda *dda)
{
	int		pixels;
	double	pov;

	pixels = 0;
	pov = (PI / 3) / W;
	while (pixels < (W - 1))
	{
		dda->i = pixels;
		travel_through_ray(dda);
		dda->ray_angle += pov;
		pixels++;
	}
}

static bool	reached_wall(t_dda *dda, t_game *game)
{
	if (game->map->grid[dda->y][dda->x] == '1')
		return (true);
	return (false);
}

void	travel_through_ray(t_dda *dda)
{
	t_img	*tex;

	while (!reached_wall(dda, dda->game))
	{
		if (dda->x_dist < dda->y_dist)
		{
			dda->x_dist += dda->x_linelength;
			dda->x += dda->x_step;
			dda->wall_face = 0;
		}
		else
		{
			dda->y_dist += dda->y_linelength;
			dda->y += dda->y_step;
			dda->wall_face = 1;
		}
	}
	if (dda->wall_face == 0)
		dda->distance = fabs(dda->x_dist - dda->x_linelength);
	else
		dda->distance = fabs(dda->y_dist - dda->y_linelength);
	// dda->distance *= cos(dda->pl->angle - dda->ray_angle); //corrige ojo de pez
	tex = choose_texture(dda, dda->game);
	check_wall_hit(dda);
	calculate_wall_heigth_and_draw(dda, tex);
}
