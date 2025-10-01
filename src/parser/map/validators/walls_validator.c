/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:48:31 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/01 20:21:50 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	flood_fill(t_map *map, int x, int y, int **visited)
{
    // 1. fuera de límites → mapa abierto
	if (x < 0 || y < 0 || y >= map->rows || x >= map->cols)
		return false;

	// 2. espacio vacío → mapa abierto
	if (map->grid[y][x] == ' ')
		return (false);

	// 3. muro o ya visitado → OK, no expandir
	if (map->grid[y][x] == '1' || visited[y][x])
		return (true);
	visited[y][x] = true;

    // 4. expandirse en 4 direcciones
	return (flood_fill(map, (x + 1), y, visited)
		&& flood_fill(map, (x - 1), y, visited)
		&& flood_fill(map, x, (y + 1), visited)
		&& flood_fill(map, x, (y - 1), visited));
}

bool	is_valid_walls(t_map *map)
{
	int			**visited;
	t_player	player;

	visited = NULL;
	find_player(map->grid, &player);
	if (!create_matrix(&visited, map->rows, map->cols))
		return (false);
	if (!flood_fill(map, player.x, player.y, visited))
	{
		free_matrix(&visited, map->rows);
		return (false);
	}
	free_matrix(&visited, map->rows);
	return (true);
}
