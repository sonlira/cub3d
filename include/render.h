/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:51:40 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/03 17:35:33 by bgil-fer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

void	app_init(t_game *game);
void	put_pixel(t_img *img, int x, int y, int rgb);
void	draw_background(t_app *app);
void	draw_minimap(t_game *game);
void	draw_player_minimap(t_game *game);
void	draw_dir_minimap(t_game *game);
void	hook(t_game *game);

void	initialize_dda(t_player *player, t_game *game);
int		render_frame(t_game *game);
void	render_images(t_game *g);
void	draw_front(t_dda *dda);
void	travel_through_ray(t_dda *dda);
t_img	*choose_texture(t_dda *dda, t_game *g);
void	check_wall_hit(t_dda *dda);
void	calculate_wall_heigth_and_draw(t_dda *dda, t_img *text);
// void	cast_single_ray(t_game *game);

// void	cast_single_ray_minimap(t_game *game);
#endif
