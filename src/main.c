/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/17 13:55:39 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game_parser(argc, argv, &game);
	player_init(game.map, &game.player);
	app_init(&game);
	// mlx_loop_hook(game.app->mlx, render_frame, &game);
	mlx_loop(game.app->mlx);
	game_free(&game);
	return (0);
}
