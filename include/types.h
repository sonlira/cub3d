/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:41:39 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/05 14:34:40 by abaldelo         ###   ########.fr       */
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
	char	*textures[NUM_TEXTURES]; // Rutas a las texturas [NO, SO, WE, EA].
	int		floor_rgb[RGB_COMPONENTS]; // Color del suelo en RGB [R, G, B].
	int		ceiling_rgb[RGB_COMPONENTS]; // Color del techo en RGB [R, G, B].
	int		floor_color; // Color del suelo empaquetado en formato 0xRRGGBB.
	int		ceiling_color; // Color del techo empaquetado en formato 0xRRGGBB.
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
	char	**grid; // Mapa en forma de matriz de caracteres [rows][cols].
	int		rows; // Número total de filas en el mapa.
	int		cols; // Número total de columnas en el mapa.
}	t_map;

/**
 * @struct s_player
 * @brief Representa al jugador dentro del mapa.
 * 
 * Esta estructura almacena la posición y orientación inicial del jugador,
 * así como su dirección de mirada y el plano de cámara usado para el cálculo
 * de raycasting.
 */
typedef struct s_player
{
	double	x; /**< Posición X del jugador en coordenadas del mapa. */
	double	y; /**< Posición Y del jugador en coordenadas del mapa. */
	char	dir; /**< Dirección inicial (N, S, E, W) tomada del mapa. */
	double	dir_x; /**< Componente X del vector de dirección. */
	double	dir_y; /**< Componente Y del vector de dirección. */
	double	plane_x;/**< Componente X del plano de cámara (raycasting). */
	double	plane_y;/**< Componente Y del plano de cámara (raycasting). */
}	t_player;


/**
 * @struct s_img
 * @brief Representa una imagen utilizada por la librería mlx.
 * 
 * Esta estructura contiene la información necesaria para manipular
 * una imagen en memoria, incluyendo su dirección de píxeles y
 * los parámetros de formato.
 */
typedef struct s_img
{
	void	*img; // Puntero a la imagen creada por mlx.
	char	*addr;//Dirección de memoria donde comienzan los datos de la imagen.
	int		bpp; // Bits por píxel de la imagen (bits per pixel).
	int		line_len;// Longitud de una línea de píxeles en bytes. 
	int		endian; // Indicador del orden de bytes (endianess) de la imagen.
}	t_img;

/**
 * @struct s_app
 * @brief Representa la aplicación principal que gestiona mlx.
 * 
 * Esta estructura almacena los punteros principales a la instancia de mlx,
 * la ventana del programa y el frame actual, así como los colores del
 * techo y el suelo.
 */
typedef struct s_app
{
	void	*mlx; /**< Puntero al contexto principal de mlx. */
	void	*win; /**< Puntero a la ventana creada por mlx. */
	t_img	frame; /**< Imagen que representa el frame actual a renderizar. */
	int		ceil_rgb; /**< Color RGB del techo (ceiling). */
	int		floor_rgb; /**< Color RGB del suelo (floor). */
}	t_app;

/**
 * @struct s_game
 * @brief Estado principal del juego.
 * 
 * Contiene punteros a la configuración y al mapa, que son
 * necesarios para inicializar y ejecutar el juego.
 */
typedef struct s_game
{
	t_config	*cfg; // Puntero a la configuración (texturas, colores, etc.).
	t_map		*map; // Puntero al mapa (grid, filas, columnas). */
	t_player	player; // Campo player (x, y, dir, etc.).*/
	t_app		*app; // Puntero a app (mlx, win, img, etc)
}	t_game;

#endif
