/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:52:12 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:39:59 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/**
 * @brief Mensajes predefinidos de error usados en el parser y en la validación.
 */
# define ERR_ALLOC "Error: memory allocation failed\n"

// Program arguments errors
# define ERR_USAGE        "Usage: %s <map.cub>\n"
# define ERR_INVALID_ARGS "Error: Invalid number of arguments.\
\nUsage: %s <map.cub>\n"
# define ERR_EMPTY_ARG    "Error: empty argument\n"

// File validation errors
# define ERR_FILE_OPEN       "Error: could not open file\n"
# define ERR_FILE_EXT        "Error: file must have .cub extension\n"
# define ERR_FILE_EMPTY      "Error: file is empty\n"

// Texture validation errors
# define ERR_TEXTURE_ARGS    "Error: invalid texture arguments\n"
# define ERR_TEXTURE_ID      "Error: invalid texture identifier\n"
# define ERR_TEXTURE_FILE    "Error: invalid texture file\n"
# define ERR_TEXTURE_DUP     "Error: duplicate texture entry\n"

// Color configuration errors
# define ERR_COLOR_ARGS       "Error: invalid color arguments\n"
# define ERR_COLOR_ID	      "Error: invalid color identifier\n"
# define ERR_COLOR_FORMAT     "Error: invalid color format (expected R,G,B)\n"
# define ERR_COLOR_RANGE      "Error: color values must be in range 0-255\n"
# define ERR_COLOR_DUP        "Error: duplicate color entry\n"

// Config parser errors
# define ERR_CONFIG_LINE      "Error: invalid configuration line\n"
# define ERR_CONFIG_UNKNOWN   "Error: unknown configuration identifier\n"
# define ERR_CONFIG_INCOMPLETE "Error: incomplete configuration\n"

// Map validation errors
# define ERR_MAP_MISSING       "Error: map section is missing\n"
# define ERR_MAP_CHAR          "Error: invalid character in map\n"
# define ERR_MAP_OPEN          "Error: map is not closed by walls\n"
# define ERR_MAP_PLAYER        "Error: missing or multiple player \
start positions\n"

#endif
