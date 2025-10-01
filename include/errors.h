/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:52:12 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/01 20:17:23 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/**
 * @brief Error al fallar la asignación de memoria dinámica.
 */
# define ERR_ALLOC "Error: memory allocation failed\n"

//========================== Program arguments errors ==========================

/**
 * @brief Mensaje de uso correcto del programa.
 */
# define ERR_USAGE "Usage: %s <map.cub>\n"

/**
 * @brief Error cuando el número de argumentos es inválido.
 */
# define ERR_INVALID_ARGS "Error: Invalid number of arguments.\n\
Usage: %s <map.cub>\n"

/**
 * @brief Error cuando un argumento está vacío.
 */
# define ERR_EMPTY_ARG "Error: empty argument\n"

// ========================== File validation errors ===========================

/**
 * @brief Error al abrir el archivo de mapa.
 */
# define ERR_FILE_OPEN "Error: could not open file\n"

/**
 * @brief Error cuando el archivo no tiene la extensión .cub.
 */
# define ERR_FILE_EXT "Error: file must have .cub extension\n"

/**
 * @brief Error cuando el archivo de mapa está vacío.
 */
# define ERR_FILE_EMPTY "Error: file is empty\n"

// ========================== Texture validation errors ========================

/**
 * @brief Error cuando los argumentos de textura son inválidos.
 */
# define ERR_TEXTURE_ARGS "Error: invalid texture arguments\n"

/**
 * @brief Error cuando el identificador de textura no es válido.
 */
# define ERR_TEXTURE_ID "Error: invalid texture identifier\n"

/**
 * @brief Error cuando el archivo de textura no es válido.
 */
# define ERR_TEXTURE_FILE "Error: invalid texture file\n"

/**
 * @brief Error cuando una textura está definida más de una vez.
 */
# define ERR_TEXTURE_DUP "Error: duplicate texture entry\n"

// ========================== Color configuration errors =======================

/**
 * @brief Error cuando los argumentos de color son inválidos.
 */
# define ERR_COLOR_ARGS "Error: invalid color arguments\n"

/**
 * @brief Error cuando el identificador de color no es válido.
 */
# define ERR_COLOR_ID "Error: invalid color identifier\n"

/**
 * @brief Error cuando el formato del color no es válido (se espera R,G,B).
 */
# define ERR_COLOR_FORMAT "Error: invalid color format (expected R,G,B)\n"

/**
 * @brief Error cuando un valor de color no está en el rango 0-255.
 */
# define ERR_COLOR_RANGE "Error: color values must be in range 0-255\n"

/**
 * @brief Error cuando un color está definido más de una vez.
 */
# define ERR_COLOR_DUP "Error: duplicate color entry\n"

// ========================== Config parser errors =============================

/**
 * @brief Error cuando una línea de configuración no es válida.
 */
# define ERR_CONFIG_LINE "Error: invalid configuration line\n"

/**
 * @brief Error cuando se encuentra un identificador desconocido.
 */
# define ERR_CONFIG_UNKNOWN "Error: unknown configuration identifier\n"

/**
 * @brief Error cuando la configuración está incompleta.
 */
# define ERR_CONFIG_INCOMPLETE "Error: incomplete configuration\n"

// ========================== Map validation errors ============================

/**
 * @brief Error cuando la sección del mapa falta en el archivo.
 */
# define ERR_MAP_MISSING "Error: map section is missing\n"

/**
 * @brief Error cuando el mapa contiene un carácter no válido.
 */
# define ERR_MAP_CHAR "Error: invalid character in map\n"

/**
 * @brief Error cuando el mapa no está cerrado por muros.
 */
# define ERR_MAP_OPEN "Error: map is not closed by walls\n"

/**
 * @brief Error cuando el mapa no tiene jugador o tiene más de uno.
 */
# define ERR_MAP_PLAYER "Error: missing or multiple player start positions\n"

/**
 * @brief Error cuando el mapa contiene una línea vacía o solo espacios
 * dentro del bloque del mapa.
 */
# define ERR_MAP_EMPTY_LINE "Error: Map contains an empty line or only spaces \
inside the map block.\n"

/**
 * @brief Error cuando las dimensiones del mapa no son válidas
 * (menores al mínimo requerido o mayores al máximo permitido).
 */
# define ERR_MAP_SIZE "Error: Invalid map dimensions.\n"

#endif
