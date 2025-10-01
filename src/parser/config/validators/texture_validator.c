/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:30:28 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:31:00 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_texture_args(int tex_argc, char **tex_argv)
{
	return (is_valid_argc(tex_argc) && is_valid_args(tex_argc, tex_argv));
}

static bool	is_valid_texture_id(char *tex_id)
{
	return (!ft_strcmp(tex_id, "NO") || !ft_strcmp(tex_id, "SO")
		|| !ft_strcmp(tex_id, "WE") || !ft_strcmp(tex_id, "EA"));
}

static bool	is_valid_texture_file(char *tex_file)
{
	return (is_valid_extension(tex_file, ".xpm")
		&& is_file_openable(tex_file)
		&& !is_empty_file(tex_file));
}

static bool	is_duplicate_texture(t_config *config, t_texture type)
{
	return (config->textures[type] != NULL);
}

bool	validate_texture(t_config *config, int tex_argc, char **tex_argv)
{
	if (!is_valid_texture_args(tex_argc, tex_argv))
		return (show_error_message(ERR_TEXTURE_ARGS));
	if (!is_valid_texture_id(tex_argv[0]))
		return (show_error_message(ERR_TEXTURE_ID));
	if (!is_valid_texture_file(tex_argv[1]))
		return (show_error_message(ERR_TEXTURE_FILE));
	if (is_duplicate_texture(config, parse_texture_type(tex_argv[0])))
		return (show_error_message(ERR_TEXTURE_DUP));
	return (true);
}
