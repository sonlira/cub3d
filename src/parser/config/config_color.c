/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:30:08 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/11 17:45:46 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	pack_rgb(int rgb[RGB_COMPONENTS])
{
	return ((rgb[R] << 16) | (rgb[G] << 8) | rgb[B]);
}

static bool	parse_rgb_values(const char *str, int rgb[RGB_COMPONENTS])
{
	int	component;
	int	index;

	component = 0;
	index = 0;
	while (*str)
	{
		while (ft_isdigit(*str))
		{
			component = component * 10 + (*str - '0');
			if (!is_valid_component(component))
				return (show_error_message(ERR_COLOR_RANGE));
			rgb[index] = component;
			str++;
		}
		if (*str)
		{
			if (*str == ',' && ++index < RGB_COMPONENTS)
				component = 0;
			str++;
		}
	}
	return (true);
}

static bool	parse_color(t_config *config, char color_key, const char *str)
{
	return ((color_key == 'F' && parse_rgb_values(str, config->floor_rgb))
		|| (color_key == 'C' && parse_rgb_values(str, config->ceiling_rgb)));
}

static bool	parse_color_key_value(char *key, const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
	*key = *(*str)++;
	while (**str && ft_isspace(**str))
		(*str)++;
	if (!**str || !ft_isdigit(**str))
		return (show_error_message(ERR_COLOR_ARGS));
	return (true);
}

bool	color_config(t_config *config, const char *line)
{
	char		color_key;
	const char	*rgb_str;

	rgb_str = line;
	if (!parse_color_key_value(&color_key, &rgb_str))
		return (false);
	if (!validate_color(config, color_key, rgb_str))
		return (false);
	if (!parse_color(config, color_key, rgb_str))
		return (false);
	config->floor_color = pack_rgb(config->floor_rgb);
	config->ceiling_color = pack_rgb(config->ceiling_rgb);
	return (true);
}
