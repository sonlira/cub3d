/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:57:21 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/03 20:06:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	t_config_free(t_config *config)
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

static void	t_map_free(t_map *map)
{
	if (!map)
		return ;
	if (map->grid)
		ft_free_split(&map->grid);
	free(map);
}

void	game_free(t_game *game)
{
	if (!game)
		return ;
	if (game->cfg)
		t_config_free(game->cfg);
	if (game->map)
		t_map_free(game->map);
}
