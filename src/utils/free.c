/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:57:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/05 15:52:26 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	config_free(t_config *config)
{
	int	i;

	if (!config)
		return ;
	i = 0;
	while (i < NUM_TEXTURES)
	{
		free(config->textures[i]);
		config->textures[i] = NULL;
		i++;
	}
	free(config);
}

static void	map_free(t_map *map)
{
	if (!map)
		return ;
	if (map->grid)
		ft_free_split(map->grid);
	free(map);
}

static void	app_destroy(t_app *app)
{
	if (app->frame.img)
		mlx_destroy_image(app->mlx, app->frame.img);
	// if (app->frame.addr)
	// 	free(app->frame.addr);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	free(app);
}

void	game_free(t_game *game)
{
	if (!game)
		return ;
	if (game->cfg)
		config_free(game->cfg);
	if (game->map)
		map_free(game->map);
	if (game->app)
		app_destroy(game->app);
}
