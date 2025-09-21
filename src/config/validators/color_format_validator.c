/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_format_validator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:31:43 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:31:46 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_valid_commas(const char *rgb_str)
{
	return (ft_count_char(rgb_str, ',') == 2);
}

static bool	is_valid_digits(const char *rgb_str)
{
	int	count;

	count = 0;
	while (*rgb_str)
	{
		if (ft_isdigit(*rgb_str))
			count++;
		rgb_str++;
	}
	return (count >= 3 && count <= 9);
}

/**
 * @brief Verifica si una cadena cumple con la secuencia "R,G,B".
 * 
 * Ejemplo válido: "255, 255, 255"
 * Ejemplos inválidos:
 * - Cadena vacía.
 * - ",255,255" (empieza con coma).
 * - "255,,255" (coma duplicada).
 * - "255,255," (termina con coma).
 * - "255, x, 255" (caracter no numérico).
 * 
 * La validación permite espacios entre números y comas, pero exige que
 * cada componente comience con al menos un dígito.
 * 
 * @param rgb_str Cadena de texto a validar.
 * @return true si la cadena tiene un formato válido "R,G,B", 
 *  false en caso contrario.
 */
static bool	is_valid_sequence(const char *rgb_str)
{
	if (!*rgb_str)
		return (false);
	while (*rgb_str)
	{
		if (!ft_isdigit(*rgb_str)) // Si el primer o el caracter despues de la `,` no es digito, false
			return (false);
		while (ft_isdigit(*rgb_str)) // Saltamos los caracteres nemericos
			rgb_str++;
		while (ft_isspace(*rgb_str)) // Si hay espacios los saltamos
			rgb_str++;
		if (*rgb_str) // Si aun existe un caracter 
		{
			if (*rgb_str != ',') // Y no es una coma, false
				return (false);
			rgb_str++;
			while (ft_isspace(*rgb_str))
				rgb_str++;
			if (!*rgb_str) // Si llegamos a final de cadena, false (Porque significa que la `,` es el ultimo char)
				return (false);
		}
	}
	return (true);
}

bool	is_valid_format_rgb(const char *rgb_str)
{
	return (is_valid_commas(rgb_str)
		&& is_valid_digits(rgb_str)
		&& is_valid_sequence(rgb_str));
}
