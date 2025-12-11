/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:25:32 by bgil-fer          #+#    #+#             */
/*   Updated: 2025/12/11 17:49:57 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perp_distance_and_wall_height(t_ray *r)
{
	if (r->side == 0)
		r->perp_wall_dist = (r->side_dist_x - r->delta_dist_x);
	else
		r->perp_wall_dist = (r->side_dist_y - r->delta_dist_y);
	if (r->perp_wall_dist < EPSILON)
		r->perp_wall_dist = EPSILON;
	r->line_height = (int)(H / r->perp_wall_dist);
	r->draw_start = -r->line_height / 2 + H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_height / 2 + H / 2;
	if (r->draw_end >= H)
		r->draw_end = H - 1;
}

void	choose_texture(t_ray *r, t_game *game)
{
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			r->texture = &game->e;
		else
			r->texture = &game->w;
	}
	else
	{
		if (r->ray_dir_y > 0)
			r->texture = &game->s;
		else
			r->texture = &game->n;
	}
}

void	calculate_wall_x(t_ray *r, t_player *pl)
{
	if (r->side == 0)
		r->wall_x = pl->y + r->perp_wall_dist * r->ray_dir_y;
	else
		r->wall_x = pl->x + r->perp_wall_dist * r->ray_dir_x;
	r->wall_x -= floor(r->wall_x);
}

void	map_wall_x_to_tex_x(t_ray *r)
{
	r->tex_x = (int)(r->wall_x * (double)PIXELS);
	if ((r->side == 0 && r->ray_dir_x < 0)
		|| (r->side == 1 && r->ray_dir_y > 0))
	{
		r->tex_x = PIXELS - r->tex_x - 1;
	}
}

void	vertical_drawing_loop(t_ray *r, int x, t_game *game)
{
	int				y;
	int				tex_y;
	unsigned int	color;
	double			tex_pos;
	double			step;

	step = 1.0 * PIXELS / r->line_height;
	tex_pos = (r->draw_start - H / 2 + r->line_height / 2) * step;
	y = r->draw_start;
	while (y < r->draw_end)
	{
		tex_y = (int)tex_pos & (PIXELS - 1);
		tex_pos += step;
		color = get_texture_pixel(r->texture, r->tex_x, tex_y);
		put_pixel(&game->app->frame, x, y, color);
		y++;
	}
}
