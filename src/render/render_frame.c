/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:26:06 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/08 14:30:12 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_frame(t_game *game)
{
	loop_hook(game);
	mlx_clear_window(game->app->mlx, game->app->win);
	draw_background(game);
	draw_front(game);
	// draw_minimap(game);
	// draw_player_minimap(game);
	mlx_put_image_to_window(game->app->mlx, game->app->win,
		game->app->frame.img, 0, 0);
	return (0);
}
/*
int	render_frame(t_game *game)
{
	t_player	*pl = &game->player;
	int			x = 0;

	loop_hook(game);
    // 0. (Asumido) Función para dibujar el techo y el suelo.
	draw_background(game); 

	while (x < W) // Itera sobre cada columna de la pantalla (W=1024)
	{
		// 1. Cálculo del Rayo
		double	camera_x = 2 * x / (double)W - 1; 
		double	ray_dir_x = pl->dir_x + pl->plane_x * camera_x;
		double	ray_dir_y = pl->dir_y + pl->plane_y * camera_x;

		int		map_x = (int)pl->x;
		int		map_y = (int)pl->y;
		
		double	side_dist_x;
		double	side_dist_y;
		int		step_x;
		int		step_y;
		int		hit = 0;
		int		side; 

        // 2. Cálculo de Delta Dist (Evita división por cero)
		double	delta_dist_x = (ray_dir_x == 0) ? 1e30 : fabs(1 / ray_dir_x);
		double	delta_dist_y = (ray_dir_y == 0) ? 1e30 : fabs(1 / ray_dir_y);
        
		// 3. Cálculo de Step y Side Dist Inicial
		// ... (Lógica de inicialización de step_x, step_y, side_dist_x, side_dist_y)
		// (Mantén el código del paso 3 de la respuesta anterior aquí)
		if (ray_dir_x < 0) { step_x = -1; side_dist_x = (pl->x - map_x) * delta_dist_x; }
		else { step_x = 1; side_dist_x = (map_x + 1.0 - pl->x) * delta_dist_x; }
		if (ray_dir_y < 0) { step_y = -1; side_dist_y = (pl->y - map_y) * delta_dist_y; }
		else { step_y = 1; side_dist_y = (map_y + 1.0 - pl->y) * delta_dist_y; }

		// 4. Algoritmo DDA
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0; // Golpe en eje X (Este/Oeste)
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1; // Golpe en eje Y (Norte/Sur)
			}
			if (is_wall(game->map, map_x, map_y)) 
				hit = 1;
		}

		// 5. Distancia Perpendicular y Altura de la Pared
		double perp_wall_dist;
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);

		// *** Corrección: Añade EPSILON para estabilidad ***
		if (perp_wall_dist < EPSILON)
		    perp_wall_dist = EPSILON;

		int line_height = (int)(H / perp_wall_dist); // H=768

		int draw_start = -line_height / 2 + H / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + H / 2;
		if (draw_end >= H)
			draw_end = H - 1;

		// -----------------------------------------------------
		// 6. Lógica de Texturizado (El corazón del problema)
		// -----------------------------------------------------

		// 6.1. Identificar la Textura a Usar
		t_img	*texture;
		if (side == 0) // Muro Este/Oeste
		{
			if (ray_dir_x > 0)
				texture = &game->e; // Textura Este (EA)
			else
				texture = &game->w; // Textura Oeste (WE)
		}
		else // Muro Norte/Sur
		{
			if (ray_dir_y > 0)
				texture = &game->s; // Textura Sur (SO)
			else
				texture = &game->n; // Textura Norte (NO)
		}
		
		// 6.2. Calcular la coordenada 'WallX' (Punto exacto de impacto)
		double wall_x;
		if (side == 0)
			wall_x = pl->y + perp_wall_dist * ray_dir_y;
		else
			wall_x = pl->x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x); // Obtener la parte fraccional (entre 0 y 1)

		// 6.3. Mapear WallX a TexX (Columna de la textura)
		int tex_x = (int)(wall_x * (double)PIXELS); // PIXELS=64
		
		// Corrección para evitar el efecto "espejo" en algunas caras
		if ((side == 0 && ray_dir_x < 0) || (side == 1 && ray_dir_y > 0))
		{
    		tex_x = PIXELS - tex_x - 1; // Invertir en X
		}
			
		// 6.4. Bucle de Dibujo Vertical (Mapeo Y)
		double step = 1.0 * PIXELS / line_height;
		// Calcular la posición inicial de Y de la textura.
		// Se resta H/2 y se suma line_height/2 para obtener la coordenada Y real en la ventana 
		// que corresponde al inicio de la textura (texY=0).
		double tex_pos = (draw_start - H / 2 + line_height / 2) * step;

		int y = draw_start;
		while (y < draw_end)
		{
			// Calcular la coordenada Y de la textura (texY)
			int tex_y = (int)tex_pos & (PIXELS - 1); // Usar & (64-1) es un truco rápido para % 64
			tex_pos += step;
			
			// Obtener el color del píxel de la textura
			unsigned int color = get_texture_pixel(texture, tex_x, tex_y);

			// Dibujar el píxel en el frame
			put_pixel(&game->app->frame, x, y, color);
			y++;
		}
		
		x++;
	}
    
	draw_minimap(game);
	draw_player_minimap(game);
    // // 7. Renderizar Frame
	mlx_put_image_to_window(game->app->mlx, game->app->win, game->app->frame.img, 0, 0);
	return (0);
}
*/