/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:06:40 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/01 18:04:34 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

/* ************************************************************************** */
/*                        INICIALIZACIÓN DEL JUGADOR (PLAYER)                 */
/* ************************************************************************** */

/**
 * @brief Busca la posición inicial del jugador en el grid del mapa.
 *
 * Recorre la matriz `grid` buscando un carácter de spawn válido y guarda
 * las coordenadas y dirección en la estructura `t_player`.
 *
 * @param grid    Matriz de caracteres que representa el mapa.
 * @param player  Puntero a la estructura del jugador a inicializar.
 * @return true si se encontró un único spawn válido, false en caso contrario.
 */
bool	find_player(char **grid, t_player *player);

/**
 * @brief Inicializa la estructura del jugador `t_player`.
 *
 * Esta función prepara al jugador antes de empezar el juego:
 *   1. Limpia la memoria de la estructura con ft_bzero.
 *   2. Busca en el mapa la posición inicial del jugador y el carácter
 *      que indica la dirección de spawn (N, S, E, W).
 *   3. Convierte ese carácter en un vector de dirección (dir_x, dir_y).
 *   4. Calcula el plano de la cámara (plane_x, plane_y), que siempre es
 *      perpendicular a la dirección, usando el factor de campo de visión.
 *
 * @param map    Puntero al mapa que contiene el grid y la información
 *               del spawn inicial.
 * @param player Puntero a la estructura t_player que será inicializada.
 *
 * @return Nada.
 */
void	player_init(t_map *map, t_player *player);

/* ************************************************************************** */
/*                      FUNCIONES DEL JUGADOR (PLAYER)                        */
/* ************************************************************************** */

void	move_forward(t_game *game, double move_speed);
void	move_behind(t_game *game, double move_speed);
void	move_right(t_game *game, double move_speed);
void	move_left(t_game *game, double move_speed);
void	rotate_right(t_game *game, double rot_speed);
void	rotate_left(t_game *game, double rot_speed);

#endif