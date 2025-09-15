#include "cub3d.h"

bool	is_valid_argc(int argc, bool quit)
{
	if (argc != 2)
	{
		if (quit)
			error_exit("Numero de argumentos no valido.");
		else
			ft_eprintf("Numero de argumentos no valido.");
	}
	return (true);
}

bool	is_valid_args(char **argv, bool quit)
{
	if (ft_strlen(argv[1]) == 0)
	{
		if (quit)
			error_exit("El argumento no puede ser vacio.");
		else
			ft_eprintf("El argumento no puede ser vacio.");
	}
	return (true);
}

bool	is_valid_argument(int argc, char **argv, bool quit)
{
	return (is_valid_argc(argc, quit) && is_valid_args(argv, quit));
}
