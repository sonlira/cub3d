/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:48:31 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/11 17:48:09 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	flood_fill(t_map *map, int x, int y, int **visited)
{
	if (x < 0 || y < 0 || y >= map->rows || x >= map->cols)
		return (false);
	if (map->grid[y][x] == ' ')
		return (false);
	if (map->grid[y][x] == '1' || visited[y][x])
		return (true);
	visited[y][x] = true;
	return (flood_fill(map, (x + 1), y, visited)
		&& flood_fill(map, (x - 1), y, visited)
		&& flood_fill(map, x, (y + 1), visited)
		&& flood_fill(map, x, (y - 1), visited));
}

bool	is_valid_walls(t_map *map)
{
	int			**visited;
	t_player	player;

	find_player(map->grid, &player);
	visited = (int **) ft_create_matrix(map->rows, map->cols, \
		sizeof(*visited), false);
	if (!visited)
		return (false);
	if (!flood_fill(map, player.x, player.y, visited))
	{
		ft_free_matrix((void **)visited, map->rows);
		return (false);
	}
	ft_free_matrix((void **)visited, map->rows);
	return (true);
}
