/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:21:12 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:16:23 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_PARSER_H
# define CONFIG_PARSER_H

/* ************************************************************************** */
/*                           VALIDACIÓN DE ARGUMENTOS                         */
/* ************************************************************************** */

/**
 * @brief Verifica que los argumentos pasados al programa sean válidos.
 * 
 * Comprueba que la cantidad de argumentos y su validez sean correctos.
 * Si alguna validación falla, la función muestra un mensaje de error
 * y finaliza el programa con exit(EXIT_FAILURE).
 * 
 * @param argc Número de argumentos recibidos.
 * @param argv Lista de argumentos recibidos.
 */
void	requiere_valid_program_args(int argc, char **argv);

/**
 * @brief Comprueba si la cantidad de argumentos es la esperada.
 * 
 * No muestra mensajes de error, solo devuelve el resultado de la validación.
 * 
 * @param argc Número de argumentos recibidos.
 * @return true si la cantidad es válida, false en caso contrario.
 */
bool	is_valid_argc(int argc);

/**
 * @brief Comprueba si los argumentos recibidos son válidos.
 * 
 * No muestra mensajes de error, solo devuelve el resultado de la validación.
 * 
 * @param argc Número de argumentos recibidos.
 * @param args Lista de argumentos recibidos.
 * @return true si los argumentos son válidos, false en caso contrario.
 */
bool	is_valid_args(int argc, char **args);

/* ************************************************************************** */
/*                           VALIDACIÓN DE ARCHIVOS                           */
/* ************************************************************************** */

/**
 * @brief Verifica que un archivo de configuración sea válido.
 * 
 * Comprueba que:
 * - Tenga la extensión correcta (ej: ".cub").
 * - Se pueda abrir en modo lectura.
 * - No esté vacío.
 * 
 * Si alguna validación falla, la función muestra un mensaje de error
 * y finaliza el programa con exit(EXIT_FAILURE).
 * 
 * @param file Ruta del archivo a validar.
 */
void	requiere_valid_file(const char *file);

/**
 * @brief Comprueba si la extensión de un archivo es válida.
 * 
 * No muestra mensajes de error, solo devuelve el resultado de la validación.
 * 
 * @param file_path Ruta del archivo.
 * @param file_extension Extensión esperada (ej: ".cub").
 * @return true si la extensión coincide, false en caso contrario.
 */
bool	is_valid_extension(const char *file_path, const char *file_extension);

/**
 * @brief Verifica si un archivo se puede abrir en modo lectura.
 * 
 * No muestra mensajes de error, solo devuelve el resultado de la validación.
 * 
 * @param file Ruta del archivo.
 * @return true si el archivo se puede abrir, false en caso contrario.
 */
bool	is_file_openable(const char *file);

/**
 * @brief Verifica si un archivo está vacío.
 * 
 * No muestra mensajes de error, solo devuelve el resultado de la validación.
 * 
 * @param file Ruta del archivo.
 * @return true si el archivo está vacío, false si contiene datos.
 */
bool	is_empty_file(const char *file);

/* ************************************************************************** */
/*                           PARSER DE CONFIGURACIÓN                          */
/* ************************************************************************** */

/**
 * @brief Parsea un archivo de configuración y
 * carga los datos en la estructura del juego.
 * 
 * @param game Puntero a la estructura principal del juego.
 * @param file_fd Descriptor de archivo del archivo de configuración abierto.
 */
void	config_parser(t_game *game, unsigned int file_fd);

/**
 * @brief Comprueba si la configuración cargada está completa y lista para usar.
 * 
 * @param config Puntero a la estructura de configuración.
 * @return true si la configuración está completa, false en caso contrario.
 */
bool	config_is_complete(t_config *config);

/* ************************************************************************** */
/*                           CONFIGURACIÓN DE COLORES                         */
/* ************************************************************************** */

/**
 * @brief Procesa una línea de configuración que define un color.
 * 
 * En caso de error, muestra un mensaje descriptivo en stderr.
 * 
 * @param config Puntero a la estructura de configuración.
 * @param line Línea de texto con la definición de color.
 * @return true si el color se procesó correctamente, false en caso contrario.
 */
bool	color_config(t_config *config, const char *line);

/**
 * @brief Comprueba si un componente de color es válido (rango 0–255).
 * 
 * No muestra mensajes de error, solo devuelve el resultado de la validación.
 * 
 * @param component Valor numérico del componente.
 * @return true si es válido, false en caso contrario.
 */
bool	is_valid_component(int component);

/**
 * @brief Verifica si una cadena tiene un formato RGB válido.
 * 
 * Comprueba que la cadena cumpla:
 * - Exactamente 2 comas.
 * - Entre 3 y 9 dígitos en total.
 * - Formato correcto "R,G,B".
 * 
 * No muestra mensajes de error, solo devuelve el resultado de la validación.
 * 
 * @param rgb_str Cadena de texto a validar (ej: "255,128,0").
 * @return true si el formato es válido, false en caso contrario.
 */
bool	is_valid_format_rgb(const char *rgb_str);

/**
 * @brief Valida la definición de un color antes de procesarlo.
 * 
 * Realiza las siguientes comprobaciones:
 * - Que el identificador de color (`key`) sea válido
 *  (ej: 'F' = floor, 'C' = ceiling).
 * - Que el formato de la cadena RGB sea válido (usando is_valid_format_rgb()).
 * - Que el color no haya sido definido previamente en la configuración.
 * 
 * En caso de error, muestra un mensaje descriptivo en stderr,
 * pero no termina el programa.
 * 
 * @param config Puntero a la estructura de configuración
 *  (usado para detectar duplicados).
 * @param key Identificador del color ('F' o 'C').
 * @param rgb_str Cadena con la definición del color en formato "R,G,B".
 * @return true si la definición de color es válida y no está duplicada, 
 *  false en caso contrario.
 */
bool	validate_color(t_config *config, const char key, const char *rgb_str);

/* ************************************************************************** */
/*                           CONFIGURACIÓN DE TEXTURAS                        */
/* ************************************************************************** */

/**
 * @brief Procesa una línea de configuración que define una textura.
 * 
 * En caso de error, muestra un mensaje descriptivo en stderr.
 * 
 * @param config Puntero a la estructura de configuración.
 * @param line Línea de texto con la definición de la textura.
 * @return true si la textura se procesó correctamente, false en caso contrario.
 */
bool	texture_config(t_config *config, const char *line);

/**
 * @brief Determina el tipo de textura a partir de su identificador.
 * 
 * No muestra mensajes de error, solo devuelve el resultado de la validación.
 * 
 * @param id Identificador de textura (ej: "NO", "SO", "WE", "EA").
 * @return Tipo de textura (enumeración t_texture).
 */
t_texture	parse_texture_type(const char *id);

/**
 * @brief Valida los argumentos de una definición de textura antes de procesarla.
 * 
 * Realiza las siguientes comprobaciones:
 * - Que la cantidad de argumentos sea exactamente 2: {"ID", "./file.xpm"}.
 * - Que el identificador de la textura (ID) sea válido 
 * (ej: "NO", "SO", "WE", "EA").
 * - Que el archivo de textura sea válido:
 *      - Tenga extensión correcta (ej: ".xpm").
 *      - Pueda abrirse en modo lectura.
 *      - No esté vacío.
 * - Que la textura no haya sido definida previamente en la configuración.
 * 
 * En caso de error, muestra un mensaje descriptivo en stderr,
 *  pero no termina el programa.
 * 
 * @param config Puntero a la estructura de configuración 
 *  (usado para detectar duplicados).
 * @param tex_argc Cantidad de argumentos relacionados con la textura.
 * @param tex_argv Lista de argumentos de textura (ej: {"NO", "./path.xpm"}).
 * @return true si la textura es válida y no está duplicada,
 *  false en caso contrario.
 */
bool	validate_texture(t_config *config, int tex_argc, char **tex_argv);

#endif /* CONFIG_PARSER_H */
