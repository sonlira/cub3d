/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:47:10 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/30 13:52:18 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	create_matrix(int ***matrix, size_t rows, size_t cols)
{
	size_t	i;

	if (!matrix || *matrix || rows < 1 || cols < 1)
		return (false);
	*matrix = ft_calloc(rows, sizeof(int *));
	if (!*matrix)
		return (false);
	i = 0;
	while (i < rows)
	{
		(*matrix)[i] = ft_calloc(cols, sizeof(int));
		if (!(*matrix)[i])
			return (free_matrix(matrix, i), false);
		i++;
	}
	return (true);
}
