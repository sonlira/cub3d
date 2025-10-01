/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:31:54 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/01 20:11:40 by abaldelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_valid_argc(int argc)
{
	return (argc == 2);
}

bool	is_valid_args(int argc, char **argv)
{
	int	i;

	if (argc < 1)
		return (false);
	i = 0;
	while (i < argc)
	{
		if (!argv[i] || !argv[i][0])
			return (false);
		i++;
	}
	return (true);
}

void	require_valid_program_args(int argc, char **argv)
{
	if (!is_valid_argc(argc))
		exit_with_error_message(ERR_INVALID_ARGS);
	if (!is_valid_args(argc, argv))
		exit_with_error_message(ERR_EMPTY_ARG);
}
