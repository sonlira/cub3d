/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:52:41 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/11 17:56:31 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_UTILS_H
# define CUBE_UTILS_H

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
 * Primero llama a `game_free(game)` para liberar memoria dinámica,
 * luego muestra el mensaje de error y termina el programa con
 *  `exit(EXIT_FAILURE)`.
 *
 * @param game     Puntero al estado principal del juego (t_game).
 * @param message  Mensaje de error que se mostrará antes de salir.
 */
void	free_game_and_exit_error(t_game *game, const char *message);

/**
 * @brief Libera todos los recursos del juego y finaliza la ejecución.
 *
 * Esta función se utiliza para terminar el programa liberando
 * previamente toda la memoria asociada a la estructura `t_game`.
 * No muestra mensajes de error ni realiza otras acciones;
 * simplemente libera los recursos y finaliza el proceso con @p code.
 *
 * @param game Puntero a la estructura del juego que se debe liberar.
 * @param code Código de salida pasado a exit().
 */
void	free_game_and_exit(t_game *game, int code);

/* ************************************************************************** */
/*                            FUNCIONES DE LIBERACIÓN                         */
/* ************************************************************************** */

/**
 * @brief Libera todos los recursos asociados a una instancia de t_game.
 *
 * @details
 * Esta función libera de forma ordenada la memoria dinámica utilizada
 * dentro de la estructura principal del juego:
 * - Llama a `config_free` para liberar la configuración.
 * - Llama a `map_free` para liberar el mapa.
 * - LLama a `app_destroy` para liberar mlx.
 * - Finalmente libera la propia estructura `t_game`.
 *
 * @param game Puntero a la estructura principal del juego (t_game).
 */
void	game_free(t_game *game);

#endif
