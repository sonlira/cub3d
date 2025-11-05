/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:28:50 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/05 18:04:13 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	close_hook(t_game *game)
{
	free_game_and_exit(game, EXIT_SUCCESS);
	return (0);
}

static int	key_hook(int key, t_game *game)
{
	if (key == XK_Escape)
		return (close_hook(game));
	return (0);
}

void	hook(t_game *game)
{
	mlx_hook(game->app->win, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(game->app->win, DestroyNotify, StructureNotifyMask, close_hook,
		game);
}
