/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:45:09 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/30 13:45:30 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	dup_str_array_into(char ***dst, char **orig)
{
	size_t	i;
	size_t	size;

	if (!dst ||!orig || !*orig)
		return (false);
	if (*dst)
		ft_free_split(dst);
	size = ft_count_elements((const char **)orig);
	*dst = ft_calloc((size + 1), sizeof(char *));
	if (!*dst)
		return (false);
	i = 0;
	while (orig[i])
	{
		(*dst)[i] = ft_strdup(orig[i]);
		if (!(*dst)[i])
			return (ft_free_split(dst), false);
		i++;
	}
	return (true);
}
