/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/30 20:09:16 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/**
 * @brief Valor especial que indica que un componente RGB aún no fue asignado.
 */
# define RGB_UNSET -1

/**
 * @brief Valor mínimo permitido para un componente RGB (rojo, verde o azul).
 */
# define RGB_MIN 0

/**
 * @brief Valor máximo permitido para un componente RGB (rojo, verde o azul).
 */
# define RGB_MAX 255

/**
 * @brief Número total de texturas requeridas por el proyecto.
 */
# define NUM_TEXTURES 4

/**
 * @brief Cantidad de componentes que forman un color RGB (rojo, verde y azul).
 */
# define RGB_COMPONENTS 3

/**
 * @brief Valor que representa una línea vacía o compuesta solo por espacios.
 */
# define LINE_EMPTY 0

/**
 * @brief Longitud del identificador de color en el mapa ('F' o 'C').
 */
# define COLOR_ID_LEN 1

/**
 * @brief Longitud del identificador de textura en el mapa 
 * (ejemplos: "NO", "SO", "WE", "EA").
 */
# define TEXTURE_ID_LEN 2

/**
 * @brief Dimensión mínima de filas (alto) que debe tener el mapa.
 */
# define MAP_MIN_ROWS 3

/**
 * @brief Dimensión mínima de columnas (ancho) que debe tener el mapa.
 */
# define MAP_MIN_COLS 3

/**
 * @brief Límite máximo de filas (alto) permitido en el mapa.
 */
# define MAP_MAX_ROWS 256

/**
 * @brief Límite máximo de columnas (ancho) permitido en el mapa.
 */
# define MAP_MAX_COLS 256



#endif