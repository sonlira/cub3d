/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:51:40 by abaldelo          #+#    #+#             */
/*   Updated: 2025/11/17 18:26:11 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

void	app_init(t_game *game);
void	put_pixel(t_img *img, int x, int y, int rgb);
void	draw_background(t_app *app);
void	draw_minimap(t_game *game);
void	hook(t_game *game);
// int		render_frame(t_game *game);
// void	cast_single_ray(t_game *game);

#endif
