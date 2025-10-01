/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:13:27 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/01 17:38:49 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	add_spaces(char **str, int size)
{
	char	*tmp;
	char	*src;
	int		i;

	i = 0;
	if ((int)ft_strlen(*str) == size)
		return (true);
	tmp = ft_calloc((size + 1), sizeof(char));
	if (!tmp)
		return (show_error_message(ERR_ALLOC));
	ft_memset(tmp, ' ', size);
	src = *str;
	while (src[i])
	{
		tmp[i] = src[i];
		i++;
	}
	free(*str);
	*str = tmp;
	return (true);
}

bool	format_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		if (!add_spaces(&map->grid[i], map->cols))
			return (false);
		i++;
	}
	return (true);
}
