/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:16:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/03 20:15:15 by bgil-fer         ###   ########.fr       */
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
			if (y == 0 || y == SCALE - 1 || x == 0 || x == SCALE - 1)
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
	int	py;
	int	px;
	int dy;
	int dx;
	int	i;

	px = game->player.x * SCALE + SCALE / 2;
	py = game->player.y * SCALE + SCALE / 2;
	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			put_pixel(&game->app->frame, px + dx, py + dy, COLOR_MINIMAP_PLAYER);
			++dx;
		}
		++dy;
	}
	i = 1;
	while (i <= SCALE)
	{
		int lx = px + game->player.dir_x * i;
		int ly = py + game->player.dir_y * i;
		put_pixel(&game->app->frame, lx, ly, COLOR_MINIMAP_WALL);
		++i;
	}
}
