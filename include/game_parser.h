/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_parser.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:14:31 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/01 19:22:48 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_PARSER_H
# define GAME_PARSER_H

# include "config_parser.h"
# include "map_parser.h"

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
void	require_valid_program_args(int argc, char **argv);

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
void	require_valid_file(const char *file);

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
/*                               PARSEO DEL JUEGO                             */
/* ************************************************************************** */

/**
 * @brief Orquesta el proceso de parseo del juego a partir de los argumentos
 *        de línea de comandos y el archivo de entrada.
 *
 * La función valida los argumentos del programa, abre el archivo de mapa
 * proporcionado, ejecuta el parser de configuración y de mapa, e inicializa
 * al jugador dentro de la estructura `t_game`. 
 *
 * Si ocurre un error en cualquiera de las fases (argumentos inválidos,
 * archivo no válido, fallo en el parser o ausencia de jugador válido),
 * la función aborta la ejecución mostrando el mensaje de error
 * correspondiente.
 *
 * @param argc  Número de argumentos recibidos por el programa.
 * @param argv  Array con los argumentos de línea de comandos.
 * @param game  Puntero a la estructura principal del juego que será llenada.
 */
void	game_parser(int argc, char **argv, t_game *game);


#endif