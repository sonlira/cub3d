/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:51:40 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/08 17:23:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

void			app_init(t_game *game);
void			put_pixel(t_img *img, int x, int y, int rgb);
void			draw_background(t_game *game);
void			draw_minimap(t_game *game);
void			hook(t_game *game);
int				loop_hook(t_game *game);
unsigned int	get_texture_pixel(t_img *tex, int x, int y);
void			render_images(t_game *g);

void			perp_distance_and_wall_height(t_ray *r);
void			choose_texture(t_ray *r, t_game *game);
void			calculate_wall_x(t_ray *r, t_player *pl);
void			map_wall_x_to_tex_x(t_ray *r);
void			vertical_drawing_loop(t_ray *r, int x, t_game *game);
void			draw_front(t_game *game);

int				render_frame(t_game *game);
#endif
