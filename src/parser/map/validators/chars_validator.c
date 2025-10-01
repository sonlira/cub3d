/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:03:16 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/01 20:05:54 by abaldelo         ###   ########.fr       */
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

bool	validate_map_line(char *line, int length, bool *in_map)
{
	if (length == LINE_EMPTY && *in_map)
		return (show_error_message(ERR_MAP_EMPTY_LINE));
	if (length > LINE_EMPTY && !is_valid_map_line(line))
		return (show_error_message(ERR_MAP_CHAR));
	if (length == LINE_EMPTY && !*in_map)
		return (true);
	if (!*in_map)
		*in_map = true;
	return (true);
}
