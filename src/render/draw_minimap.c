/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:16:51 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/08 19:12:12 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	draw_square(t_app *app, t_mmap s, int size, int color)
{
	int		initial_sx;
	t_mmap	offset;

	initial_sx = s.x;
	offset.y = 0;
	while (offset.y < size)
	{
		offset.x = 0;
		while (offset.x < size)
		{
			put_pixel(&app->frame, initial_sx + offset.x, s.y + offset.y,
				color);
			offset.x++;
		}
		offset.y++;
	}
}

static void	draw_player(t_app *app, t_mmap cent, int size, int color)
{
	t_mmap	start;
	int		half_size;

	half_size = size / 2;
	start.x = cent.x - half_size;
	start.y = cent.y - half_size;
	draw_square(app, start, size, color);
}

void	draw_minimap(t_game *game)
{
	int		row;
	int		col;
	t_mmap	screen;
	t_mmap	player_center;

	row = 0;
	while (row < game->map->rows)
	{
		col = 0;
		while (col < game->map->cols)
		{
			screen.x = col * SCALE;
			screen.y = row * SCALE;
			if (game->map->grid[row][col] == MAP_WALL)
				draw_square(game->app, screen, SCALE, COLOR_W);
			else
				draw_square(game->app, screen, SCALE, COLOR_F);
			col++;
		}
		row++;
	}
	player_center.x = (int)(game->player.x * SCALE);
	player_center.y = (int)(game->player.y * SCALE);
	draw_player(game->app, player_center, PL_SCALE, COLOR_P);
}
