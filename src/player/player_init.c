/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:04:47 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/03 20:06:21 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_set_dir(double x, double y, t_player *player)
{
	player->dir_x = x;
	player->dir_y = y;
}

/**
 * @brief Inicializa la dirección del jugador según su spawn en el mapa.
 *
 * Convierte el carácter de spawn leído (N, S, E, W) en un vector unitario
 * que representa la dirección inicial en el plano 2D.
 *
 * Direcciones posibles:
 *   N (Norte) ↑ : ( 0, -1)
 *   S (Sur)   ↓ : ( 0,  1)
 *   E (Este)  → : ( 1,  0)
 *   W (Oeste) ← : (-1,  0)
 *
 * @param player Puntero a la estructura t_player donde se guardará
 *               la dirección inicial (dir_x, dir_y).
 *
 * @return Nada.
 */
static void	player_init_dir(t_player *player)
{
	if (player->dir == MAP_SPAWN_N)
		player_set_dir(0, -1, player);
	else if (player->dir == MAP_SPAWN_S)
		player_set_dir(0, 1, player);
	else if (player->dir == MAP_SPAWN_E)
		player_set_dir(1, 0, player);
	else if (player->dir == MAP_SPAWN_W)
		player_set_dir(-1, 0, player);
}

bool	find_player(char **grid, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (is_valid_spawn_char(grid[y][x]))
			{
				player->x = x;
				player->y = y;
				player->dir = grid[y][x];
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}

void	player_init(t_map *map, t_player *player)
{
	ft_bzero(player, sizeof(*player));
	find_player(map->grid, player);
	player_init_dir(player);
	// El plano siempre depende de la dirección (dir_x, dir_y)
	player->plane_x = -player->dir_y * FOV_FACTOR;
	player->plane_y = player->dir_x * FOV_FACTOR;
}


// void	player_rotate(t_player *player)
// {

// }

// void	player_set_pos(double x, double y, t_player *player)
// {
// 	player->x = x;
// 	player->y = y;
// }
/**	
 

Norte
↑
↑
• → → Este → su perpendicular es (0,1) o (0,-1)
↓
↓
Sur
*/