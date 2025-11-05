/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/05 14:59:13 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game_parser(argc, argv, &game);
	player_init(game.map, &game.player);
	app_init(&game);
	mlx_loop(game.app->mlx);
	return (0);
}
