/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:28:50 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/01 17:52:40 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	close_hook(t_game *game)
{
	free_game_and_exit(game, EXIT_SUCCESS);
	return (0);
}

static int	key_press(int key, t_game *game)
{
	if (key == XK_Escape)
		return (close_hook(game));
	else if (key == XK_w)
		game->input.w = true;
	else if (key == XK_s)
		game->input.s = true;
	else if (key == XK_a)
		game->input.a = true;
	else if (key == XK_d)
		game->input.d = true;
	else if (key == XK_Left)
		game->input.left = true;
	else if (key == XK_Right)
		game->input.right = true;
	return (0);
}

static int	key_release(int key, t_game *game)
{
	if (key == XK_w)
		game->input.w = false;
	else if (key == XK_s)
		game->input.s = false;
	else if (key == XK_a)
		game->input.a = false;
	else if (key == XK_d)
		game->input.d = false;
	else if (key == XK_Left)
		game->input.left = false;
	else if (key == XK_Right)
		game->input.right = false;
	return (0);
}

void	hook(t_game *game)
{
	mlx_hook(game->app->win, KeyPress, KeyPressMask, key_press, game);
	mlx_hook(game->app->win, KeyRelease, KeyReleaseMask, key_release, game);
	mlx_hook(game->app->win, DestroyNotify, StructureNotifyMask, close_hook,
		game);
}
