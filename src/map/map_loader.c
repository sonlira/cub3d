#include "cub3d.h"

typedef struct s_iterator
{
	size_t	i;
	size_t	j;
	size_t	k;
}	t_iterator;

void	init_iterator(t_iterator *it)
{
	if (!it)
		return ;
	ft_bzero(it, sizeof(t_iterator));
}

static t_map	*t_map_create(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	return (map);
}

static bool	array_push(char ***array, const char *value)
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
	while (size != 0 && (*array)[it.i])
	{
		new_array[it.j] = ft_strdup((*array)[it.i++]);
		if (!new_array[it.j++])
			return (ft_free_split(&new_array), false);
	}
	new_array[it.j] = ft_strdup(value);
	if (!new_array[it.j])
		return (ft_free_split(&new_array), false);
	ft_free_split(array);
	*array = new_array;
	return (true);
}


static int	get_line_map_length(const char *str)
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

static bool is_valid_map_char(char c)
{
    return (c == MAP_WALL || c == MAP_EMPTY
        || c == MAP_SPACE || c == MAP_SPAWN_E
        || c == MAP_SPAWN_N || c == MAP_SPAWN_S
        || c == MAP_SPAWN_W);
}

static bool is_valid_map_str(const char *line)
{
    while (*line)
    {
        if (!is_valid_map_char(*line))
            return (false);
        line++;
    }
    return (true);
}

static bool	parse_map_line(t_map *map, char *line, bool *in_map)
{
	int	lenght;
	printf("[[%s]]\n",line);
	lenght = get_line_map_length(line);
	if (lenght == LINE_EMPTY && *in_map)
		return (show_error_message("Espacios entre lineas del mapa\n"));//Poner un mensaje de error que diga "Que no puede existir espacios entre las lineas del mapa" (o algo asi)
    if (lenght > LINE_EMPTY && !is_valid_map_str(line))
		return (show_error_message("caracter no valide en map_str\n")); // hay caracteres invalidos en la linea
    if (lenght == LINE_EMPTY && !*in_map)
        return (true);
    if (!*in_map)
	{
    	*in_map = true;
	}
	if (map->cols < lenght)
		map->cols = lenght;
	map->rows++;
    return (array_push(&map->grid, line));
}

static bool	parse_map_file(t_map *map, unsigned int fd)
{
	char	*line;
    bool    in_map;

    in_map = false;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line[(ft_strlen(line) - 1)] = '\0';
		if (!parse_map_line(map, line, &in_map))
		{
			free(line);
			return (false);
		}
		free(line);
	}
	return (true);
}

void	map_loader(t_game *game, unsigned int file_fd)
{
	t_map	*map;

	map = t_map_create();
	if (!map)
    {
        free(game->cfg);
		exit_with_error_message(ERR_ALLOC); // Se debe liberar memoria de config antes de salir
    }
	if (!parse_map_file(map, file_fd))
	{
        free(game->cfg);
        if (map->grid)
            ft_free_split(&map->grid);
		free(map);
		exit(EXIT_FAILURE);
	}
    free(game->cfg);
    ft_print_str_array(map->grid);

	int i = 0;
	while (map->grid[i])
	{
		printf("%zu\n",ft_strlen(map->grid[i]));
		i++;
	}
	printf("rows[[%d]] cols[[%d]]\n",map->rows, map->cols);
	// idea, para rellenar con espacios, se me ocurre reservar memoria, inicalizar todo con espacios usando memset y poner el ultimo caracter en nulo para que no se desvorde
	// despues simplemente capiar la cadena ahi, luego liberar la anterior y hacer que la matriz apunte a la nueva cadena
    ft_free_split(&map->grid);
	free(map);
	exit(EXIT_FAILURE);
	game->map = map;
}
