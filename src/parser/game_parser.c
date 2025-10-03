/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:41:54 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/03 20:20:10 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	game_init(t_game *game)
{
	ft_bzero(game, sizeof(*game));
}

void	game_parser(int argc, char **argv, t_game *game)
{
	int	fd;

	game_init(game);
	require_valid_program_args(argc, argv);
	require_valid_file(argv[1]);
	open_file(argv[1], &fd);
	config_parser(game, fd);
	map_parser(game, fd);
	close(fd);
}
