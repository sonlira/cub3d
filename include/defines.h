/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/04 14:29:32 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/**
 * @brief Valor del ancho (width) de la pantalla creada por mlx
 */
# define W 1024

/**
 * @brief Valor del alto (height) de la pantalla creada por mlx
 */
# define H 768

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

/**
 * @brief Factor que define la amplitud del campo de visión (FOV).
 *
 * Este valor se multiplica por el vector perpendicular a la dirección
 * del jugador para calcular el plano de la cámara.
 *
 * Convenciones típicas:
 *   0.66 → ≈ 66° de FOV (estándar en Wolfenstein / cub3D)
 *   1.00 → ≈ 90° de FOV
 *
 * Ajustar este valor permite abrir o cerrar el ángulo de visión.
 */
# define FOV_FACTOR 0.66

#endif