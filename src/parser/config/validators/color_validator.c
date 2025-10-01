/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:31:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:31:35 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_component(int component)
{
	return (component >= RGB_MIN && component <= RGB_MAX);
}

static bool	is_valid_color_id(const char color_id)
{
	return (color_id == 'F' || color_id == 'C');
}

static bool	is_duplicate_color(int rgb[RGB_COMPONENTS])
{
	return (rgb[R] != RGB_UNSET && rgb[G] != RGB_UNSET && rgb[B] != RGB_UNSET);
}

bool	validate_color(t_config *config, const char key, const char *rgb_str)
{
	if (!is_valid_color_id(key))
		return (show_error_message(ERR_COLOR_ID));
	if (!is_valid_format_rgb(rgb_str))
		return (show_error_message(ERR_COLOR_FORMAT));
	if ((key == 'F' && is_duplicate_color(config->floor_rgb))
		|| (key == 'C' && is_duplicate_color(config->ceiling_rgb)))
		return (show_error_message(ERR_COLOR_DUP));
	return (true);
}
