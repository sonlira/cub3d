/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/11 17:58:48 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/**
 * @brief Título de la pantalla creada por mlx
 */
# define WIN_TITLE "CUB3D"

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

/**
 * @brief Tamaño de celda del minimapa.
 */
# define SCALE 10

/**
 * @brief Color de las celdas tipo pared (`1`) del minimapa.
 * @example
 * 11184886  // Gris piedra claro
 * 13158600  // Gris claro
 * 3947580   // Gris oscuro
 */
# define COLOR_W 11184886

/**
 * @brief Color de las celdas tipo suelo/vacío (`0`) del minimapa.
 * @example
 * 5265224   // Marrón oscuro (estilo dungeon)
 * 3281178   // Azul grisáceo oscuro
 * 14408694  // Arena clara
 */
# define COLOR_F 5265224

/**
 * @brief Color de player en minimapa.
 * @example
 * 16724796  // Rojo brillante
 * 65450     // Verde lima
 * 3982847   // Azul brillante
 * 16764928  // Amarillo
 * 16743168  // Naranja
 */
# define COLOR_P 16724796

/**
 * @brief Tamaño de player en minimapa
 * @note Se debe cumplir esta condicíon PLAYER_SCALE < SCALE / 2
 */
# define PL_SCALE 3

# define PI 3.14159265358979323846

# define PIXELS 64

/**
 * @brief Margen de seguridad para la detección de colisiones.
 * * Se utiliza para evitar que el jugador se "clipee" o se meta en las esquinas.
 * 0.2 es un valor seguro.
 */
# define COLLISION_PADDING 0.2

# define EPSILON 0.0001

# define MOVE_SPEED 0.05

# define ROT_SPEED 0.03

#endif