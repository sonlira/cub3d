/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:28:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/05 18:02:32 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_app	*app_create(void)
{
	t_app	*app;

	app = ft_calloc(1, sizeof(*app));
	if (!app)
		return (NULL);
	return (app);
}

void	app_init(t_game *game)
{
	game->app = app_create();
	if (!game->app)
		exit_with_error_message(ERR_ALLOC);
	game->app->ceil_rgb = game->cfg->ceiling_color;
	game->app->floor_rgb = game->cfg->floor_color;
	window_init(game->app);
	hook(game);
}
