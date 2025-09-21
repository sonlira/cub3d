/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:52:41 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:12:49 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

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

#endif

