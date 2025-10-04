/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:03:16 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/04 13:10:42 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_spawn_char(const char c)
{
	return (c == MAP_SPAWN_E || c == MAP_SPAWN_N
		|| c == MAP_SPAWN_S || c == MAP_SPAWN_W);
}

static bool	is_valid_map_char(const char c)
{
	return (c == MAP_WALL || c == MAP_EMPTY
		|| c == MAP_SPACE || is_valid_spawn_char(c));
}

static bool	is_valid_map_line(const char *line)
{
	while (*line)
	{
		if (!is_valid_map_char(*line))
			return (false);
		line++;
	}
	return (true);
}

static bool	is_blank_line(const char *line)
{
	while (ft_isspace(*line))
		line++;
	return (*line == '\0');
}

bool	validate_map_line(const char *line, bool *in_map)
{
	if (is_blank_line(line) && *in_map)
		return (show_error_message(ERR_MAP_EMPTY_LINE));
	if (!is_blank_line(line) && !is_valid_map_line(line))
		return (show_error_message(ERR_MAP_CHAR));
	if (!is_blank_line(line) && !*in_map)
		*in_map = true;
	return (true);
}
