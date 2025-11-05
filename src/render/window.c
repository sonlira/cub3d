/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:08:50 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/05 15:06:29 by abaldelo         ###   ########.fr       */
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

static void	put_pixel(t_img *img, int x, int y, int rgb)
{
	char	*dst;

	dst = NULL;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = rgb;
}

static void	draw_background(t_app *app)
{
	int	y;
	int	x;
	int	rgb;

	y = 0;
	while (y < H)
	{
		if (y < (H / 2))
			rgb = app->ceil_rgb;
		else
			rgb = app->floor_rgb;
		x = 0;
		while (x < W)
		{
			put_pixel(&app->frame, x, y, rgb);
			++x;
		}
		++y;
	}
}

static int	key_hook(int key, t_game *game)
{
	if (key == XK_Escape)
		free_game_and_exit(game, EXIT_SUCCESS);
	return (0);
}

static int	close_hook(t_game *game)
{
	free_game_and_exit(game, EXIT_SUCCESS);
	return (0);
}

void	app_init(t_game *game)
{
	t_app	*app;

	app = app_create();
	if (!app)
		exit_with_error_message(ERR_ALLOC);
	app->ceil_rgb = game->cfg->ceiling_color;
	app->floor_rgb = game->cfg->floor_color;
	app->mlx = mlx_init();
	app->win = mlx_new_window(app->mlx, W, H, "cub3d -- window");
	app->frame.img = mlx_new_image(app->mlx, W, H);
	app->frame.addr = mlx_get_data_addr(app->frame.img, &app->frame.bpp, \
								&app->frame.line_len, &app->frame.endian);
	draw_background(app);
	mlx_put_image_to_window(app->mlx, app->win, app->frame.img, 0, 0);
	game->app = app;
	mlx_hook(app->win, KeyPress, KeyPressMask, key_hook, game);
	mlx_hook(app->win, DestroyNotify, StructureNotifyMask, close_hook, game);
}
