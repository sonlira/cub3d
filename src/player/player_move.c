/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:21:52 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/08 15:55:45 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_wall(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->cols || y < 0 || y >= map->rows)
		return (true);
	return (map->grid[y][x] == MAP_WALL);
}

void	move_forward(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x + game->player.dir_x * move_speed;
	new_y = game->player.y + game->player.dir_y * move_speed;
	if (!is_wall(game->map,
			(int)(new_x + game->player.dir_x * COLLISION_PADDING),
		(int)game->player.y))
	{
		game->player.x = new_x;
	}
	if (!is_wall(game->map, (int)game->player.x,
			(int)(new_y + game->player.dir_y * COLLISION_PADDING)))
	{
		game->player.y = new_y;
	}
}

void	move_behind(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;
	double	coll_dir_x;
	double	coll_dir_y;

	new_x = game->player.x - game->player.dir_x * move_speed;
	new_y = game->player.y - game->player.dir_y * move_speed;
	coll_dir_x = -game->player.dir_x;
	coll_dir_y = -game->player.dir_y;
	if (!is_wall(game->map,
			(int)(new_x + coll_dir_x * COLLISION_PADDING),
		(int)game->player.y))
	{
		game->player.x = new_x;
	}
	if (!is_wall(game->map, (int)game->player.x,
			(int)(new_y + coll_dir_y * COLLISION_PADDING)))
	{
		game->player.y = new_y;
	}
}

void	move_right(t_game *game, double move_speed)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = game->player.dir_y;
	perp_y = -game->player.dir_x;
	new_x = game->player.x + perp_x * move_speed;
	new_y = game->player.y + perp_y * move_speed;
	if (!is_wall(game->map, (int)(new_x + perp_x * COLLISION_PADDING),
		(int)game->player.y))
	{
		game->player.x = new_x;
	}
	if (!is_wall(game->map, (int)game->player.x,
			(int)(new_y + perp_y * COLLISION_PADDING)))
	{
		game->player.y = new_y;
	}
}

void	move_left(t_game *game, double move_speed)
{
	double	perp_x;
	double	perp_y;
	double	new_x;
	double	new_y;

	perp_x = -game->player.dir_y;
	perp_y = game->player.dir_x;
	new_x = game->player.x + perp_x * move_speed;
	new_y = game->player.y + perp_y * move_speed;
	if (!is_wall(game->map, (int)(new_x + perp_x * COLLISION_PADDING),
		(int)game->player.y))
	{
		game->player.x = new_x;
	}
	if (!is_wall(game->map, (int)game->player.x,
			(int)(new_y + perp_y * COLLISION_PADDING)))
	{
		game->player.y = new_y;
	}
}
