/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:21:48 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/01 18:04:21 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_game *game, double rot_speed)
{
	t_point		old_dir;
	t_point		old_plane;
	t_player	*play;

	play = &game->player;
	old_dir.x = play->dir_x;
	old_dir.y = play->dir_y;
	play->dir_x = old_dir.x * cos(rot_speed) - old_dir.y * sin(rot_speed);
	play->dir_y = old_dir.x * sin(rot_speed) + old_dir.y * cos(rot_speed);
	old_plane.x = play->plane_x;
	old_plane.y = play->plane_y;
	play->plane_x = old_plane.x * cos(rot_speed) - old_plane.y * sin(rot_speed);
	play->plane_y = old_plane.x * sin(rot_speed) + old_plane.y * cos(rot_speed);
}

void	rotate_left(t_game *game, double rot_speed)
{
	t_point		old_dir;
	t_point		old_pla;
	t_player	*play;

	play = &game->player;
	old_dir.x = play->dir_x;
	old_dir.y = play->dir_y;
	play->dir_x = old_dir.x * cos(-rot_speed) - old_dir.y * sin(-rot_speed);
	play->dir_y = old_dir.x * sin(-rot_speed) + old_dir.y * cos(-rot_speed);
	old_pla.x = play->plane_x;
	old_pla.y = play->plane_y;
	play->plane_x = old_pla.x * cos(-rot_speed) - old_pla.y * sin(-rot_speed);
	play->plane_y = old_pla.x * sin(-rot_speed) + old_pla.y * cos(-rot_speed);
}
