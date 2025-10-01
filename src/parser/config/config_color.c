/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:30:08 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:30:16 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Empaqueta un color RGB en un entero de 24 bits.
 * 
 * Toma los tres componentes separados (R, G, B) y los combina en un único
 * valor en formato hexadecimal 0xRRGGBB:
 * 
 * - R se desplaza 16 bits a la izquierda.
 * - G se desplaza 8 bits a la izquierda.
 * - B queda en los 8 bits menos significativos.
 * 
 * Ejemplo:
 *   rgb = {255, 128, 64}
 *   resultado = 0xFF8040
 * 
 * @param rgb Array de 3 enteros con los componentes R, G y B.
 * @return Entero no signado con el color empaquetado en formato 0xRRGGBB.
 */
static unsigned int	pack_rgb(int rgb[RGB_COMPONENTS])
{
	return ((rgb[R] << 16) | (rgb[G] << 8) | rgb[B]);
}


static bool	parse_rgb_values(const char *str, int rgb[RGB_COMPONENTS])
{
	int	component;
	int	index;

	component = 0;
	index = 0;
	while (*str)
	{
		while (ft_isdigit(*str))
		{
			component = component * 10 + (*str - '0');
			if (!is_valid_component(component))
				return (show_error_message(ERR_COLOR_RANGE));
			rgb[index] = component;
			str++;
		}
		if (*str)
		{
			if (*str == ',' && ++index < RGB_COMPONENTS) // Esto es una chapusa
				component = 0;
			str++;
		}
	}
	return (true);
}

static bool	parse_color(t_config *config, char color_key, const char *str)
{
	return ((color_key == 'F' && parse_rgb_values(str, config->floor_rgb))
		|| (color_key == 'C' && parse_rgb_values(str, config->ceiling_rgb)));
}

/**
 * @brief Extrae la clave de color y prepara el puntero a la cadena RGB.
 * 
 * Ejemplo de entrada: "    F      244,234,0"
 * 
 * Comportamiento:
 * - Omite espacios iniciales.
 * - Guarda en `key` el primer carácter no espacio (ej: 'F' o 'C').
 * - Avanza el puntero `str` hasta que apunte al inicio de la definición RGB.
 * - Verifica que la cadena resultante comience con un dígito válido.
 * 
 * Si no hay cadena RGB válida después de la clave, muestra un mensaje
 * de error y devuelve false.
 * 
 * @param key Puntero a char donde se almacena el identificador del color
 *  ('F' o 'C').
 * @param str Doble puntero a la cadena de configuración; al final quedará
 *            apuntando al inicio de la secuencia RGB (ej: "244,234,0").
 * @return true si se extrajo correctamente la clave y la cadena es válida,
 *         false si ocurre un error de formato.
 */
static bool	parse_color_key_value(char *key, const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
	*key = *(*str)++;
	while (**str && ft_isspace(**str))
		(*str)++;
	if (!**str || !ft_isdigit(**str))
		return (show_error_message(ERR_COLOR_ARGS));
	return (true);
}

bool	color_config(t_config *config, const char *line)
{
	char		color_key;
	const char	*rgb_str;

	rgb_str = line;
	if (!parse_color_key_value(&color_key, &rgb_str))
		return (false);
	if (!validate_color(config, color_key, rgb_str))
		return (false);
	if (!parse_color(config, color_key, rgb_str))
		return (false);
	config->floor_color = pack_rgb(config->floor_rgb);
	config->ceiling_color = pack_rgb(config->ceiling_rgb);
	return (true);
}
