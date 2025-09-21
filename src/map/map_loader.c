#include "cub3d.h"

// static t_map	*t_map_create(void)
// {
// 	t_map	*map;

// 	map = ft_calloc(1, sizeof(t_map));
// 	if (!map)
// 		return (NULL);
// 	return (map);
// }

// static bool	parse_map_line(t_map *map, char *line)
// {
// 	return (true);
// }

// static bool	parse_map_file(t_map *map, unsigned int fd)
// {
// 	char	*line;

// 	while (true)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		line[(ft_strlen(line) - 1)] = '\0';
// 		if (!parse_map_line(map, line))
// 		{
// 			free(line);
// 			return (false);
// 		}
// 		free(line);
// 	}
// 	return (true);
// }

// void	map_loader(t_game *game, unsigned int file_fd)
// {
// 	t_map	*map;

// 	map = t_config_create();
// 	if (!map)
// 		exit_with_error_message(ERR_ALLOC); // Se debe liberar memoria de config antes de salir
// 	if (!parse_map_file(map, file_fd))
// 	{
// 		free(map);
// 		exit(EXIT_FAILURE);
// 	}
// 	free(map);
// 	exit(EXIT_FAILURE);
// 	game->map = map;
// }
