/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:28:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/01 19:18:14 by abaldelo         ###   ########.fr       */
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

static void	window_init(t_game *game)
{
	t_app	*app;

	// test
	// int w = SCALE * game->map->cols;
	// int h = SCALE * game->map->rows;
	
	app = game->app;
	app->mlx = mlx_init();

	// app->win = mlx_new_window(app->mlx, w, h, WIN_TITLE);
	// app->frame.img = mlx_new_image(app->mlx, w, h);

	app->win = mlx_new_window(app->mlx, W, H, WIN_TITLE);
	app->frame.img = mlx_new_image(app->mlx, W, H);
	app->frame.addr = mlx_get_data_addr(app->frame.img, &app->frame.bpp,
			&app->frame.line_len, &app->frame.endian);

	draw_background(app);

	draw_minimap(game); // es parte del bonus
	draw_player_minimap(game); // es parte del bonus
	// cast_single_ray_minimap(game);
	mlx_put_image_to_window(app->mlx, app->win, app->frame.img, 0, 0);
}

void	app_init(t_game *game)
{
	game->app = app_create();
	if (!game->app)
		exit_with_error_message(ERR_ALLOC);
	game->app->ceil_rgb = game->cfg->ceiling_color;
	game->app->floor_rgb = game->cfg->floor_color;
	window_init(game);
	hook(game);
}
