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

static void	calculate_ray(t_ray *r, int x, t_player *pl)
{
	r->camera_x = 2 * x / (double)W -1;
	r->ray_dir_x = pl->dir_x + pl->plane_x * r->camera_x;
	r->ray_dir_y = pl->dir_y + pl->plane_y * r->camera_x;
}

static void	calculate_delta(t_ray *r)
{
	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->ray_dir_x);
	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1 / r->ray_dir_y);
}

static void	calculate_step_and_side_dist(t_ray *r, t_player *pl)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (pl->x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - pl->x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (pl->y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - pl->y) * r->delta_dist_y;
	}
}

static void	dda(t_ray *r, t_game *game)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (is_wall(game->map, r->map_x, r->map_y))
			r->hit = 1;
	}
}

void	draw_front(t_game *game)
{
	t_player	*pl;
	t_ray		ray;
	int			x;

	pl = &game->player;
	x = 0;
	while (x < W)
	{
		ft_bzero(&ray, sizeof(ray));
		ray.map_x = (int)pl->x;
		ray.map_y = (int)pl->y;
		calculate_ray(&ray, x, pl);
		calculate_delta(&ray);
		calculate_step_and_side_dist(&ray, pl);
		dda(&ray, game);
		perp_distance_and_wall_height(&ray);
		choose_texture(&ray, game);
		calculate_wall_x(&ray, pl);
		map_wall_x_to_tex_x(&ray);
		vertical_drawing_loop(&ray, x, game);
		x++;
	}
}
