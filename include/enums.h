/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:46:24 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:06:38 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENUMS_H
# define ENUMS_H


/**
 * @enum e_key
 * @brief Códigos de teclado usados en el juego.
 * 
 * Asocia las teclas más relevantes para movimiento y control
 * a sus respectivos códigos numéricos (X11/ASCII).
 */
typedef enum e_key
{
	ESC_KEY		= 65307, /**< Tecla ESC (salir o cerrar programa). */
	KEY_W		= 119, /**< Tecla 'W' (mover hacia adelante / arriba). */
	KEY_A		= 97, /**< Tecla 'A' (mover hacia la izquierda). */
	KEY_S		= 115, /**< Tecla 'S' (mover hacia atrás / abajo). */
	KEY_D		= 100, /**< Tecla 'D' (mover hacia la derecha). */

	KEY_UP		= 65362, /**< Flecha arriba. */
	KEY_DOWN	= 65364, /**< Flecha abajo. */
	KEY_LEFT	= 65361, /**< Flecha izquierda. */
	KEY_RIGHT	= 65363, /**< Flecha derecha. */
}	t_key;


/**
 * @enum e_texture
 * @brief Identificadores de texturas según la orientación de la pared.
 * 
 * Se usan como índices en un array de texturas cargadas.
 */
typedef enum e_texture
{
	TEX_NO, /**< Textura para paredes que miran al Norte. */
	TEX_SO, /**< Textura para paredes que miran al Sur. */
	TEX_WE, /**< Textura para paredes que miran al Oeste. */
	TEX_EA, /**< Textura para paredes que miran al Este. */
}	t_texture;


/**
 * @enum e_color
 * @brief Índices para componentes de color RGB.
 * 
 * Usados típicamente en un arreglo de 3 enteros: [R, G, B].
 */
typedef enum e_color
{
	R, /**< Componente Roja. */
	G, /**< Componente Verde. */
	B, /**< Componente Azul. */
}	t_color;

/**
 * @enum e_map_char
 * @brief Caracteres válidos en el mapa del juego.
 * 
 * Usados para validar el archivo de mapa y facilitar la lectura del código.
 */
typedef enum e_map_char
{
	MAP_WALL	= '1', /**< Pared. */
	MAP_EMPTY	= '0', /**< Espacio vacío / suelo. */
	MAP_SPAWN_N = 'N', /**< Posición inicial del jugador mirando al Norte. */
	MAP_SPAWN_S = 'S', /**< Posición inicial del jugador mirando al Sur. */
	MAP_SPAWN_W = 'W', /**< Posición inicial del jugador mirando al Oeste. */
	MAP_SPAWN_E = 'E', /**< Posición inicial del jugador mirando al Este. */
	MAP_SPACE	= ' ', /**< Espacio (fuera del mapa jugable / padding). */
}	t_map_char;

#endif