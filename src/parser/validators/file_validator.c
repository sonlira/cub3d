/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaldelo <abaldelo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:31:08 by abaldelo          #+#    #+#             */
/*   Updated: 2025/10/04 13:10:02 by abaldelo         ###   ########.fr       */
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

bool	is_valid_extension(const char *file_path, const char *file_extension)
{
	char	*extension;

	extension = ft_strrchr(file_path, '.');
	if (!extension || ft_strcmp(extension, file_extension))
		return (false);
	return (true);
}

bool	is_file_openable(const char *file)
{
	int	fd;

	if (!open_file(file, &fd))
		return (false);
	close(fd);
	return (true);
}

bool	is_empty_file(const char *file)
{
	int		fd;
	char	buffer;
	size_t	read_byte;

	if (!open_file(file, &fd))
		return (false);
	read_byte = read(fd, &buffer, 1);
	close(fd);
	return (read_byte == 0);
}

void	require_valid_file(const char *file)
{
	if (!is_valid_extension(file, ".cub"))
		exit_with_error_message(ERR_FILE_EXT);
	if (!is_file_openable(file))
		exit_with_error_message(ERR_FILE_OPEN);
	if (is_empty_file(file))
		exit_with_error_message(ERR_FILE_EMPTY);
}

