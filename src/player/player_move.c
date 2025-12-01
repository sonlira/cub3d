/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:21:52 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/01 19:10:27 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *game, double move_speed)
{
	t_point	new;
	int		cell_x;
	int		cell_y;

	new.x = game->player.x + game->player.dir_x * move_speed;
	new.y = game->player.y + game->player.dir_y * move_speed;
	cell_x = (int)new.x;
	cell_y = (int)new.y;
	if (cell_x < 0 || cell_x >= game->map->cols
		|| cell_y < 0 || cell_y >= game->map->rows)
		return ;
	if (game->map->grid[cell_y][cell_x] != MAP_WALL)
	{
		game->player.x = new.x;
		game->player.y = new.y;
	}
}

void	move_behind(t_game *game, double move_speed)
{
	t_point	new;
	int		cell_x;
	int		cell_y;

	new.x = game->player.x - game->player.dir_x * move_speed;
	new.y = game->player.y - game->player.dir_y * move_speed;
	cell_x = (int)new.x;
	cell_y = (int)new.y;
	if (cell_x < 0 || cell_x >= game->map->cols
		|| cell_y < 0 || cell_y >= game->map->rows)
		return ;
	if (game->map->grid[cell_y][cell_x] != MAP_WALL)
	{
		game->player.x = new.x;
		game->player.y = new.y;
	}
}

void	move_right(t_game *game, double move_speed)
{
	t_point	new;
	t_point	perp;
	int		cell_x;
	int		cell_y;


	perp.x = game->player.dir_y;
	perp.y = -game->player.dir_x;
	new.x = game->player.x + perp.x * move_speed;
	new.y = game->player.y + perp.y * move_speed;
	cell_x = (int)new.x;
	cell_y = (int)new.y;
	if (cell_x < 0 || cell_x >= game->map->cols
		|| cell_y < 0 || cell_y >= game->map->rows)
		return ;
	if (game->map->grid[cell_y][cell_x] != MAP_WALL)
	{
		game->player.x = new.x;
		game->player.y = new.y;
	}
}

void	move_left(t_game *game, double move_speed)
{
	t_point	new;
	t_point	perp;
	int		cell_x;
	int		cell_y;

	perp.x = -game->player.dir_y;
	perp.y = game->player.dir_x;
	new.x = game->player.x + perp.x * move_speed;
	new.y = game->player.y + perp.y * move_speed;
	cell_x = (int)new.x;
	cell_y = (int)new.y;
	if (cell_x < 0 || cell_x >= game->map->cols
		|| cell_y < 0 || cell_y >= game->map->rows)
		return ;
	if (game->map->grid[cell_y][cell_x] != MAP_WALL)
	{
		game->player.x = new.x;
		game->player.y = new.y;
	}
}
