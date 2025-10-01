/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:28:13 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/01 20:20:34 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_map_dimensions(t_map *map)
{
	if (map->rows < MAP_MIN_ROWS || map->rows > MAP_MAX_ROWS)
		return (false);
	if (map->cols < MAP_MIN_COLS || map->cols > MAP_MAX_COLS)
		return (false);
	return (true);
}

bool	validate_map(t_map *map)
{
	if (!is_valid_map_dimensions(map))
		return (show_error_message(ERR_MAP_SIZE));
	if (!is_valid_player(map))
		return (show_error_message(ERR_MAP_PLAYER));
	if (!is_valid_walls(map))
		return (show_error_message(ERR_MAP_OPEN));
	return (true);
}
