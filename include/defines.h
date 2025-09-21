/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:51:58 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:15:57 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define RGB_UNSET	-1 /**< valor que indica que un componente 
aún no fue asignado */

// Rangos permitidos para los valores de cada componente RGB (rojo, verde, azul)
# define RGB_MIN   0     /**<  valor mínimo válido */
# define RGB_MAX   255   /**<  valor máximo válido */

# define NUM_TEXTURES        4	/**<  cantidad de texturas requeridas */
# define RGB_COMPONENTS      3   /**<  cantidad de valores en un color RGB */

# define LINE_EMPTY          0   /**<  línea vacía o solo espacios */
# define COLOR_ID_LEN        1   /**<  longitud del identificador de color 
('F' o 'C') */
# define TEXTURE_ID_LEN      2   /**<  longitud del identificador de textura 
(ej: "NO", "SO", "WE", "EA") */


#endif