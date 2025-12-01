/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:26:06 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/01 20:19:10 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	loop_hook(t_game *game)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.05;
	rot_speed = 0.03;
	if (game->input.w)
		move_forward(game, move_speed);
	if (game->input.s)
		move_behind(game, move_speed);
	if (game->input.a)
		move_left(game, move_speed);
	if (game->input.d)
		move_right(game, move_speed);
	if (game->input.left)
		rotate_left(game, rot_speed);
	if (game->input.right)
		rotate_right(game, rot_speed);
	return (0);
}

int	render_frame(t_game *game)
{
	loop_hook(game);
	draw_background(game->app);
	draw_minimap(game);
	draw_player_minimap(game);
	mlx_put_image_to_window(game->app->mlx, game->app->win, game->app->frame.img, 0, 0);
	// cast_single_ray(game);
	return (0);
}
