/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/22 13:16:34 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	requiere_valid_program_args(argc, argv);
	requiere_valid_file(argv[1]);
	open_file(argv[1], &fd);
	config_parser(&game, fd);
	map_loader(&game, fd);
	return (0);
}
