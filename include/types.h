/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:41:39 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:38:53 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/**
 * @struct s_config
 * @brief Contiene la configuración de recursos del juego.
 * 
 * Esta estructura almacena las rutas de las texturas y los colores
 * (en formato RGB y empaquetados) definidos en el archivo de configuración.
 */
typedef struct s_config
{
	char	*textures[NUM_TEXTURES]; /**< Rutas a las texturas de paredes 
	[NO, SO, WE, EA]. */
	int		floor_rgb[RGB_COMPONENTS]; /**< Color del suelo en formato RGB 
	separado [R, G, B]. */
	int		ceiling_rgb[RGB_COMPONENTS]; /**< Color del techo en formato RGB 
	separado [R, G, B]. */
	int		floor_color; /**< Color del suelo empaquetado en formato 
	0xRRGGBB. */
	int		ceiling_color; /**< Color del techo empaquetado en formato 
	0xRRGGBB. */
}	t_config;


/**
 * @struct s_map
 * @brief Representa el mapa del juego en forma de grilla.
 * 
 * Esta estructura contiene la matriz de caracteres que define el mapa,
 * así como sus dimensiones.
 */
typedef struct s_map
{
	char	**grid; /**< Mapa en forma de matriz de caracteres [rows][cols]. */
	int		rows; /**< Número total de filas en el mapa. */
	int		cols; /**< Número total de columnas en el mapa. */
}	t_map;


/**
 * @struct s_game
 * @brief Estado principal del juego.
 * 
 * Contiene punteros a la configuración y al mapa, que son
 * necesarios para inicializar y ejecutar el juego.
 */
typedef struct s_game
{
	t_config	*cfg; /**< Puntero a la configuración 
	(texturas, colores, etc.). */
	t_map		*map; /**< Puntero al mapa (grid, filas, columnas). */
}	t_game;

#endif
