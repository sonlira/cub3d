/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_unshift.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:43:24 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/30 13:43:52 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	array_unshift(char ***array, const char *value)
{
	t_iterator	it;
	size_t		size;
	char		**new_array;

	if (!array || !value)
		return (false);
	size = ft_count_elements((const char **)*array);
	new_array = ft_calloc((size + 2), sizeof(char *));
	if (!new_array)
		return (false);
	init_iterator(&it);
	new_array[it.j] = ft_strdup(value);
	if (!new_array[it.j++])
		return (ft_free_split(&new_array), false);
	while (size != 0 && (*array)[it.i])
	{
		new_array[it.j] = ft_strdup((*array)[it.i++]);
		if (!new_array[it.j++])
			return (ft_free_split(&new_array), false);
	}
	ft_free_split(array);
	*array = new_array;
	return (true);
}
