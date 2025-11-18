/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:16:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/18 09:09:24 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_cell_minimap(t_app *app, int mx, int my, int color)
{
	int	y;
	int	x;
	int	sy;
	int	sx;

	y = 0;
	sy = my * SCALE;
	while (y < SCALE)
	{
		x = 0;
		sx = mx * SCALE;
		while (x < SCALE)
		{
			if (y == 0 || y == SCALE -1 || x == 0 || x == SCALE -1)
				put_pixel(&app->frame, sx, sy, COLOR_MINIMAP_BORDER);
			else
				put_pixel(&app->frame, sx, sy, color);
			++sx;
			++x;
		}
		++sy;
		++y;
	}
}

void	draw_minimap(t_game *game)
{
	int		my;
	int		mx;

	my = 0;
	while (my < game->map->rows)
	{
		mx = 0;
		while (mx < game->map->cols)
		{
			if (game->map->grid[my][mx] == MAP_WALL)
				draw_cell_minimap(game->app, mx, my, COLOR_MINIMAP_WALL);
			else if (game->map->grid[my][mx] == MAP_EMPTY
					|| is_valid_spawn_char(game->map->grid[my][mx]))
				draw_cell_minimap(game->app, mx, my, COLOR_MINIMAP_FLOOR);
			++mx;
		}
		++my;
	}
}

void	draw_player_minimap(t_game *game)
{
	int	y;
	int	x;
	int	py;
	int	px;

	y = 0;
	py = game->player.y * SCALE;
	while (y < SCALE)
	{
		x = 0;
		px = game->player.x * SCALE;
		while (x < SCALE)
		{
			if (y >= SCALE / 2 - PLAYER_SCALE
				&& y <= SCALE / 2 + PLAYER_SCALE
				&& x >= SCALE / 2 - PLAYER_SCALE
				&& x <= SCALE / 2 + PLAYER_SCALE)
				put_pixel(&game->app->frame, px, py, COLOR_MINIMAP_PLAYER);
			++px;
			++x;
		}
		++py;
		++y;
	}
}
