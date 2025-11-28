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

void	initialize_dda(t_player *player)
{
	t_dda	dda;

	player->dda = &dda;
	dda.x = player->x / 64;
	dda.y = player->y / 64;
	dda.x_linelength = fabs(1 / cos(ray_angle));
	dda.y_linelength = fabs(1 / sin(ray_angle)); //ray_angle de donde sale? esta en player?
	if (cos(ray_angle) < 0)
		dda.x_step = -1;
	else
		dda.x_step = 1;
	if (sin(ray_angle) < 0)
		dda.y_step = -1;
	else
		dda.y_step = 1;
	if (dda.x_step == -1)
		dda.x_dist = (player->y / 64 - dda.x) * dda.x_linelength;
	else
		dda.x_dist = (dda.x + 1 - player->y / 64) * dda.x_linelength;
	if (dda.y_step == -1)
		dda.y_dist = (player->x / 64 - dda.y) * dda.y_linelength;
	else
		dda.y_dist = (dda.y + 1 - player->x / 64) * dda.y_linelength;
}
