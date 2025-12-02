/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:31:18 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/02 14:16:31 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	config_texture_is_complete(t_config *config)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		if (!config->textures[i])
			return (false);
		i++;
	}
	return (true);
}

static bool	config_color_is_complete(t_config *config)
{
	int	i;

	i = 0;
	while (i < RGB_COMPONENTS)
	{
		if (config->ceiling_rgb[i] == RGB_UNSET
			|| config->floor_rgb[i] == RGB_UNSET)
			return (false);
		i++;
	}
	if (config->ceiling_color == RGB_UNSET || config->floor_color == RGB_UNSET)
		return (false);
	return (true);
}

bool	config_is_complete(t_config *config)
{
	return (config_texture_is_complete(config)
		&& config_color_is_complete(config));
}
