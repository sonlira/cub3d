
#include "cub3d.h"

void	error_exit(char *msg)
{
	ft_eprintf("Error\n");
	ft_eprintf("%s\n", msg);
	exit(EXIT_FAILURE);
}
// void	error_exit_and_free();