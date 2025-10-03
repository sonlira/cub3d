/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:28 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/03 20:06:54 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_first_word_length(const char *str)
{
	int		length;

	length = 0;
	while (ft_isspace(*str))
		str++;
	while (*str && !ft_isspace(*str))
	{
		length++;
		str++;
	}
	return (length);
}

bool	open_file(const char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (false);
	return (true);
}

void	exit_with_error_message(const char *message)
{
	ft_eprintf("Error\n%s", message);
	// ft_eprintf(message);
	exit(EXIT_FAILURE);
}

bool	show_error_message(const char *message)
{
	ft_eprintf("Error\n");
	ft_eprintf(message);
	return (false);
}

void	exit_error_and_free(t_game *game, const char *message)
{
	game_free(game);
	exit_with_error_message(message);
}
