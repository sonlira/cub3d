/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:04:47 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/07 19:49:21 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	player_set_dir(double x, double y, t_player *player, char dir)
{
	player->dir_x = x;
	player->dir_y = y;
	if (dir == 'W')
		player->angle = PI;
	else if (dir == 'N')
		player->angle = PI / 2;
	else if (dir == 'S')
		player->angle = 3 * PI / 2;
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
		player_set_dir(0, -1, player, 'N');
	else if (player->dir == MAP_SPAWN_S)
		player_set_dir(0, 1, player, 'S');
	else if (player->dir == MAP_SPAWN_E)
		player_set_dir(1, 0, player, 'E');
	else if (player->dir == MAP_SPAWN_W)
		player_set_dir(-1, 0, player, 'W');
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

void	player_init(t_game *game)
{
	t_player	*pl;

	pl = &game->player;
	ft_bzero(pl, sizeof(*pl));
	find_player(game->map->grid, pl);
	player_init_dir(pl);
	// El plano siempre depende de la dirección (dir_x, dir_y)
	pl->plane_x = -pl->dir_y * FOV_FACTOR;
	pl->plane_y = pl->dir_x * FOV_FACTOR;
}

/**	
Norte
↑
↑
• → → Este → su perpendicular es (0,1) o (0,-1)
↓
↓
Sur
*/