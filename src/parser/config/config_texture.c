/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:42 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/02 14:16:31 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	parse_texture_type(const char *id)
{
	if (!ft_strcmp(id, "NO"))
		return (TEX_NO);
	if (!ft_strcmp(id, "SO"))
		return (TEX_SO);
	if (!ft_strcmp(id, "WE"))
		return (TEX_WE);
	return (TEX_EA);
}

bool	texture_config(t_config *config, const char *line)
{
	int		tex_argc;
	char	**tex_argv;

	tex_argv = ft_split(line, ' ');
	tex_argc = ft_strslen(tex_argv);
	if (!validate_texture(config, tex_argc, tex_argv))
	{
		ft_free_split(tex_argv);
		return (false);
	}
	config->textures[parse_texture_type(tex_argv[0])] = ft_strdup(tex_argv[1]);
	ft_free_split(tex_argv);
	return (true);
}
