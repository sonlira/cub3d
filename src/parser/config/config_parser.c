/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:55 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/07 17:18:45 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_config	*config_create(void)
{
	t_config	*config;

	config = ft_calloc(1, sizeof(*config));
	if (!config)
		return (NULL);
	ft_memset(config->ceiling_rgb, RGB_UNSET, sizeof(config->ceiling_rgb));
	ft_memset(config->floor_rgb, RGB_UNSET, sizeof(config->floor_rgb));
	config->floor_color = RGB_UNSET;
	config->ceiling_color = RGB_UNSET;
	return (config);
}

static int	get_first_word_length(const char *str)
{
	int		length;

	length = 0;
	while (ft_isspace(*str))
		str++;
	while (*str && !ft_isspace(*str))
	{
		length++;
		str++;
	}
	return (length);
}

static bool	parse_config_line(t_config *config, const char *line)
{
	int	lenght;

	lenght = get_first_word_length(line);
	if (lenght == LINE_EMPTY)
		return (true);
	if (lenght == COLOR_ID_LEN)
		return (color_config(config, line));
	if (lenght == TEXTURE_ID_LEN)
		return (texture_config(config, line));
	return (show_error_message(ERR_CONFIG_UNKNOWN));
}

static bool	parse_config_file(t_config *config, unsigned int fd)
{
	char	*line;

	while (!config_is_complete(config))
	{
		line = get_next_line(fd);
		if (!line)
			return (show_error_message(ERR_CONFIG_INCOMPLETE));
		if (line[(ft_strlen(line) - 1)] == '\n')
			line[(ft_strlen(line) - 1)] = '\0';
		if (!parse_config_line(config, line))
		{
			get_next_line_free(fd);
			free(line);
			return (false);
		}
		free(line);
	}
	return (true);
}

void	config_parser(t_game *game, unsigned int file_fd)
{
	game->cfg = config_create();
	if (!game->cfg)
		exit_with_error_message(ERR_ALLOC);
	if (!parse_config_file(game->cfg, file_fd))
		free_game_and_exit(game, EXIT_FAILURE);
}
