/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:29:28 by abaldelo          #+#    #+#             */
/*   Updated: 2025/09/21 15:29:33 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	open_file(const char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (false);
	return (true);
}

void	exit_with_error_message(const char *message)
{
	ft_eprintf("Error\n");
	ft_eprintf(message);
	exit(EXIT_FAILURE);
}

bool	show_error_message(const char *message)
{
	ft_eprintf("Error\n");
	ft_eprintf(message);
	return (false);
}
// void	error_exit_and_free();