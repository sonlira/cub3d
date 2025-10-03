/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:05:42 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/03 20:00:51 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	has_single_player(char **grid)
{
	char	player;
	int		y;
	int		x;

	player = MAP_EMPTY;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (is_valid_spawn_char(grid[y][x]))
			{
				if (player != MAP_EMPTY)
					return (false);
				player = grid[y][x];
			}
			x++;
		}
		y++;
	}
	return (true);

}

bool	is_valid_player(t_map *map)
{
	return (has_single_player(map->grid)
		&& find_player(map->grid, &(t_player){}));
}
