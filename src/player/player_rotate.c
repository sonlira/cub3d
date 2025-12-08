/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:21:48 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/07 19:45:01 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_game *game, double rot_speed)
{
	double		old_dir_x;
	double		old_dir_y;
	double		old_plane_x;
	double		old_plane_y;
	t_player	*pl;

	pl = &game->player;
	old_dir_x = pl->dir_x;
	old_dir_y = pl->dir_y;
	pl->dir_x = old_dir_x * cos(rot_speed) - old_dir_y * sin(rot_speed);
	pl->dir_y = old_dir_x * sin(rot_speed) + old_dir_y * cos(rot_speed);
	old_plane_x = pl->plane_x;
	old_plane_y = pl->plane_y;
	pl->plane_x = old_plane_x * cos(rot_speed) - old_plane_y * sin(rot_speed);
	pl->plane_y = old_plane_x * sin(rot_speed) + old_plane_y * cos(rot_speed);
}

void	rotate_left(t_game *game, double rot_speed)
{
	double		old_dir_x;
	double		old_dir_y;
	double		old_plane_x;
	double		old_plane_y;
	t_player	*pl;

	pl = &game->player;
	old_dir_x = pl->dir_x;
	old_dir_y = pl->dir_y;
	pl->dir_x = old_dir_x * cos(-rot_speed) - old_dir_y * sin(-rot_speed);
	pl->dir_y = old_dir_x * sin(-rot_speed) + old_dir_y * cos(-rot_speed);
	old_plane_x = pl->plane_x;
	old_plane_y = pl->plane_y;
	pl->plane_x = old_plane_x * cos(-rot_speed) - old_plane_y * sin(-rot_speed);
	pl->plane_y = old_plane_x * sin(-rot_speed) + old_plane_y * cos(-rot_speed);
}
