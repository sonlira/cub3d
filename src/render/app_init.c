/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:28:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/05 19:35:20 by abaldelo         ###   ########.fr       */
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

static void	window_init(t_app *app)
{
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, W, H, WIN_TITLE);
	app->frame.img = mlx_new_image(app->mlx, W, H);
	app->frame.addr = mlx_get_data_addr(app->frame.img, &app->frame.bpp,
			&app->frame.line_len, &app->frame.endian);
	draw_background(app);
	mlx_put_image_to_window(app->mlx, app->win, app->frame.img, 0, 0);
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
