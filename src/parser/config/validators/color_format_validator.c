/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_format_validator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:31:43 by abaldelo          #+#    #+#             */
/*   Updated: 2025/12/11 17:46:32 by bgil-fer         ###   ########.fr       */
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

static bool	is_valid_sequence(const char *rgb_str)
{
	if (!*rgb_str)
		return (false);
	while (*rgb_str)
	{
		if (!ft_isdigit(*rgb_str))
			return (false);
		while (ft_isdigit(*rgb_str))
			rgb_str++;
		while (ft_isspace(*rgb_str))
			rgb_str++;
		if (*rgb_str)
		{
			if (*rgb_str != ',')
				return (false);
			rgb_str++;
			while (ft_isspace(*rgb_str))
				rgb_str++;
			if (!*rgb_str)
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
