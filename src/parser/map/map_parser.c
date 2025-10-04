/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:18:54 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/04 13:19:40 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	*map_create(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(*map));
	if (!map)
		return (NULL);
	return (map);
}

static void	update_map_dimensions(t_map *map, int length)
{
	if (map->cols < length)
		map->cols = length;
	map->rows++;
}

static bool	parse_map_line(t_map *map, char *line, bool *in_map)
{
	if (!validate_map_line(line, in_map))
		return (false);
	if (!*in_map)
		return (true);
	update_map_dimensions(map, (int)ft_strlen(line));
	return (array_push(&map->grid, line));
}

static bool	map_loader(t_map *map, unsigned int fd)
{
	char	*line;
	bool	in_map;

	in_map = false;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!in_map)
				return (show_error_message(ERR_MAP_MISSING));
			break ;
		}
		if (line[(ft_strlen(line) - 1)] == '\n')
			line[(ft_strlen(line) - 1)] = '\0';
		if (!parse_map_line(map, line, &in_map))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (format_map(map));
}

void	map_parser(t_game *game, unsigned int file_fd)
{
	game->map = map_create();
	if (!game->map)
		free_game_and_exit_error(game, ERR_ALLOC);
	if (!map_loader(game->map, file_fd) || !validate_map(game->map))
		free_game_and_exit(game);
}
