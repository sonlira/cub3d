/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:26:06 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/11 17:44:49 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_frame(t_game *game)
{
	loop_hook(game);
	draw_background(game);
	draw_front(game);
	mlx_put_image_to_window(game->app->mlx, game->app->win,
		game->app->frame.img, 0, 0);
	return (0);
}
