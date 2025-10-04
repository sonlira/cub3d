/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:18:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/04 12:19:38 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

/* ************************************************************************** */
/*                              PARSEO DEL MAPA                               */
/* ************************************************************************** */

/**
 * @brief Comprueba si un carácter corresponde a un spawn válido del jugador.
 *
 * Caracteres válidos: 'N', 'S', 'E', 'W'.
 *
 * @param c Carácter a validar.
 * @return true si es un carácter válido de spawn, false en caso contrario.
 */
bool	is_valid_spawn_char(const char c);

/**
 * @brief Valida una línea del mapa durante el proceso de parseo.
 *
 * Se asegura de que la línea cumpla con las reglas de formato y actualiza
 * el estado de si ya se está dentro de la sección de mapa.
 *
 * @param line    Línea de texto a validar.
 * @param in_map  Bandera que indica si ya se está dentro del mapa.
 * @return true si la línea es válida, false en caso contrario.
 */
bool	validate_map_line(const char *line, bool *in_map);

/**
 * @brief Procesa el archivo de entrada para construir la representación
 *        interna del mapa en `t_game`.
 *
 * Lee las líneas del archivo, valida su formato y llena la estructura
 * `t_map` dentro de `t_game`.
 *
 * @param game    Puntero a la estructura principal del juego.
 * @param file_fd Descriptor de archivo abierto que contiene el mapa.
 */
void	map_parser(t_game *game, unsigned int file_fd);

/**
 * @brief Ajusta el formato del mapa para asegurar que tenga dimensiones
 *        consistentes y bien definidas.
 *
 * Normaliza el grid del mapa para que todas las filas tengan el mismo
 * ancho y el contenido sea manejable internamente.
 *
 * @param map Puntero a la estructura del mapa.
 * @return true si el formato es correcto, false en caso contrario.
 */
bool	format_map(t_map *map);

/**
 * @brief Verifica si el mapa contiene un jugador válido.
 *
 * Comprueba que exista exactamente un spawn del jugador en el mapa y que
 * su posición esté correctamente definida.
 *
 * @param map Puntero a la estructura del mapa.
 * @return true si el jugador es válido, false en caso contrario.
 */
bool	is_valid_player(t_map *map);

/**
 * @brief Comprueba que las paredes del mapa cierren correctamente el área.
 *
 * Valida que no existan fugas (espacios abiertos hacia el exterior) en la
 * estructura de paredes.
 *
 * @param map Puntero a la estructura del mapa.
 * @return true si las paredes son válidas, false si el mapa queda abierto.
 */
bool	is_valid_walls(t_map *map);

/**
 * @brief Ejecuta las validaciones principales del mapa.
 *
 * Revisa que el mapa tenga un formato correcto, contenga un único jugador
 * válido y que sus paredes cierren adecuadamente.
 *
 * @param map Puntero a la estructura del mapa.
 * @return true si el mapa es válido, false en caso contrario.
 */
bool	validate_map(t_map *map);

#endif