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

void	requiere_valid_program_args(int argc, char **argv)
{
	if (!is_valid_argc(argc))
		exit_with_error_message(ERR_INVALID_ARGS);
	if (!is_valid_args(argc, argv))
		exit_with_error_message(ERR_EMPTY_ARG);
}
