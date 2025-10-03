/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:52:41 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/03 20:06:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ************************************************************************** */
/*                               STRING UTILITIES                             */
/* ************************************************************************** */

/**
 * @brief Calcula la longitud de la primera palabra en una cadena.
 * 
 * La función avanza ignorando todos los espacios iniciales en `str`.
 * Después cuenta los caracteres consecutivos hasta encontrar un espacio
 * o el fin de la cadena (`'\0'`).
 * 
 * Ejemplo:
 * - "   hola mundo" → devuelve 4
 * - "   42Madrid"   → devuelve 7
 * - "   "           → devuelve 0
 * 
 * @param str Cadena de entrada.
 * @return int Longitud de la primera palabra (sin contar espacios).
 */
int		get_first_word_length(const char *str);

/* ************************************************************************** */
/*                               MANEJO DE ARCHIVOS                           */
/* ************************************************************************** */

/**
 * @brief Intenta abrir un archivo en modo lectura.
 * 
 * Utiliza la ruta pasada en `file` para abrir el archivo y asigna
 * el descriptor de archivo resultante en `fd`.
 * 
 * - En caso de éxito, devuelve true y `*fd` contendrá el descriptor válido.
 * - En caso de error, devuelve false y `*fd` no será válido.
 * 
 * @param file Ruta del archivo a abrir.
 * @param fd Puntero a un entero donde se almacenará el descriptor de archivo.
 * @return true si el archivo pudo abrirse correctamente,
 *  false en caso contrario.
 */
bool	open_file(const char *file, int *fd);

/* ************************************************************************** */
/*                               FUNCIONES DE ERROR                           */
/* ************************************************************************** */

/**
 * @brief Muestra un mensaje de error y finaliza el programa.
 * 
 * Imprime el mensaje en la salida de error estándar (stderr) y
 * termina inmediatamente la ejecución del programa con exit(EXIT_FAILURE).
 * 
 * @param message Cadena de texto con el mensaje de error a mostrar.
 */
void	exit_with_error_message(const char *message);

/**
 * @brief Muestra un mensaje de error y devuelve false.
 * 
 * Imprime el mensaje en la salida de error estándar (stderr), pero
 * no interrumpe la ejecución del programa. Se utiliza típicamente
 * en funciones de validación que necesitan devolver un estado lógico.
 * 
 * @param message Cadena de texto con el mensaje de error a mostrar.
 * @return false siempre, para integrarse en expresiones condicionales.
 */
bool	show_error_message(const char *message);

/**
 * @brief Libera todos los recursos asociados a `game` y finaliza el programa.
 *
 * Esta función debe usarse en caso de error crítico en el juego. 
 * Primero llama a `t_game_free(game)` para liberar memoria dinámica,
 * luego muestra el mensaje de error y termina el programa con
 *  `exit(EXIT_FAILURE)`.
 *
 * @param game     Puntero al estado principal del juego (t_game).
 * @param message  Mensaje de error que se mostrará antes de salir.
 */
void	exit_error_and_free(t_game *game, const char *message);

/* ************************************************************************** */
/*                            FUNCIONES DE LIBERACIÓN                         */
/* ************************************************************************** */

/**
 * @brief Libera todos los recursos asociados a una instancia de t_game.
 *
 * Esta función libera de forma ordenada la memoria dinámica utilizada
 * dentro de la estructura principal del juego:
 * - Llama a `t_config_free` para liberar la configuración.
 * - Llama a `t_map_free` para liberar el mapa.
 * - Finalmente libera la propia estructura `t_game`.
 *
 * @param game Puntero a la estructura principal del juego (t_game).
 */
void	game_free(t_game *game);

#endif

