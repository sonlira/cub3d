/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:28 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/05 14:51:47 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_with_error_message(const char *message)
{
	ft_eprintf("Error\n%s", message);
	exit(EXIT_FAILURE);
}

bool	show_error_message(const char *message)
{
	ft_eprintf("Error\n%s", message);
	return (false);
}

void	free_game_and_exit_error(t_game *game, const char *message)
{
	game_free(game);
	exit_with_error_message(message);
}

void	free_game_and_exit(t_game *game, int code)
{
	game_free(game);
	exit(code);
}
