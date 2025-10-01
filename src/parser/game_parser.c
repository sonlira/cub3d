/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:41:54 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/01 20:55:05 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	t_game_init(t_game *game)
{
	ft_bzero(game, sizeof(*game));
}

static void	t_player_init(t_map *map, t_player *player)
{
	ft_bzero(player, sizeof(*player)); // aseguras estado limpio
	find_player(map->grid, player); // llena x, y, dir
}
void	game_parser(int argc, char **argv, t_game *game)
{
	int	fd;

	t_game_init(game);
	require_valid_program_args(argc, argv);
	require_valid_file(argv[1]);
	open_file(argv[1], &fd);
	config_parser(game, fd);
	map_parser(game, fd);
	t_player_init(game->map, &game->player);
	close(fd);
	// ft_print_str_array(game->map->grid);
	// exit_error_and_free(game, "Fuera de game\n");
}
