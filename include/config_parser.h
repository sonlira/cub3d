/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:21:12 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/11 18:07:20 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_PARSER_H
# define CONFIG_PARSER_H

void		config_parser(t_game *game, unsigned int file_fd);
bool		config_is_complete(t_config *config);
bool		color_config(t_config *config, const char *line);
bool		is_valid_component(int component);
bool		is_valid_format_rgb(const char *rgb_str);
bool		validate_color(t_config *cfg, const char key, const char *rgb_str);
bool		texture_config(t_config *config, const char *line);
t_texture	parse_texture_type(const char *id);
bool		validate_texture(t_config *config, int tex_argc, char **tex_argv);
#endif
