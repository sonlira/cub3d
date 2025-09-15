
#include "cub3d.h"

bool	is_valid_extension(char *file_path, char *file_extension, bool quit)
{
	char	*extension;

	extension = ft_strrchr(file_path, '.');
	if (!extension || ft_strcmp(extension, file_extension))
	{
		if (quit)
			error_exit("La extension no es valida.");
		else
			ft_eprintf("La extension no es valida.\n");
	}
	return (true);
}

bool	open_file(char *file, int *fd, bool quit)
{
	*fd = -1;
	*fd = open(file, O_RDONLY);
	if (*fd < 0)
	{
		if (quit)
			error_exit("No se pudo abrir el fichero");
		else
			ft_eprintf("No se pudo abrir el fichero\n");
	}
	if (!quit)
		close (*fd);
	return (true);
}

bool	is_valid_file(char *file, int *fd, char *extension, bool quit)
{
	return (is_valid_extension(file, extension, quit) && \
			open_file(file, fd, quit));
}
