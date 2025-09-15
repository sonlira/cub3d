#include "cub3d.h"

t_config	*create_t_config(void)
{
	t_config	*config;

	config = ft_calloc(1, sizeof(t_config));
	if (!config)
		return (NULL);
	config->floor_color = -1;
	config->ceiling_color = -1;
	return (config);
}

t_texture	get_type_texture(char *id)
{
	if (!ft_strcmp(id, "NO"))
		return (NO);
	if (!ft_strcmp(id, "SO"))
		return (SO);
	if (!ft_strcmp(id, "WE"))
		return (WE);
	return (EA);
}

bool	is_valid_id(char *id)
{
	if (ft_strcmp(id, "NO") && ft_strcmp(id, "SO") && \
		ft_strcmp(id, "WE") && ft_strcmp(id, "EA"))
	{
		ft_eprintf("El identificador de textura no es valido.\n");
		return (false);
	}
	return (true);
}

bool	is_not_diplicate(t_config *config, t_texture type)
{
	if (config->textures[type])
	{
		ft_eprintf("Hay configuraciones repetidas.\n");
		return (false);
	}
	return (true);
}

bool	texture_config(t_config *config, char *line, int *config_count)
{
	int		fd;
	int		argc;
	char	**argv;

	argv = ft_split(line, ' ');
	argc = ft_count_elements(argv);
	if (!is_valid_argument(argc, argv, false))
		return (ft_free_split(&argv), false);
	else if (!is_valid_id(argv[0]))
		return (ft_free_split(&argv), false);
	else if (!is_valid_file(argv[1], &fd, ".xpm", false))
		return (ft_free_split(&argv), false);
	else if (!is_not_duplicate(config, get_type_texture(argv[0])))
		return (ft_free_split(&argv), false);
	config->textures[get_type_texture(argv[0])] = ft_strdup(argv[1]);
	(*config_count)++;
	ft_free_split(&argv);
	return (true);
}

bool	parse_color(int rgb[3], char *line)
{
	int current_value;
	int number_count;
	int	coma_count;
	int i;

	while (line[i] == ' ')
		i++;
	// while ()o
	
}

bool	color_config(t_config *config, char *line, int *config_count)
{
	char	id;
	int		start;

	start = 0;
	while (line[start] == ' ')
		start++;
	id = line[start];
	if (id != 'F' && id != 'C')
		return (false);
	if (id == 'F' && !parse_color(config->floor_rgb, line++))
		return (false);
	else if (!parse_color(config->ceiling_rgb, line++))
		return (false);
	return (true);
}

void	process_line(t_config *config, char *line, int *config_count)
{
	int		start;
	int		end;

	start = 0;
	while (line[start] == ' ')
		start++;
	end = start;
	while (line[end] && line[end] != ' ')
		end++;
	if (end - start == 0)
		return ;
	else if (end - start == 1)
		color_config(config, line, config_count);
	else if (end - start == 2)
		texture_config(config, line, config_count);
	else
	{
		free(config);
		error_exit("Identificador de configuracion no valido.");
	}

}

void	process_file(t_config *config, int fd, int *config_count)
{
	char	*line;

	while (true)
	{
		line = get_next_line(fd);
		if (!line || config_count == 5)
			break ;
		process_line(config, line, config_count);
		free(line);
	}
}

void	init_config_parser(t_game *game, int file_fd)
{
	t_config	*config;
	int			config_count;

	config_count = 0;
	config = create_t_config();
	process_file(config, file_fd, &config_count);
	if (config_count != 5)
	{
		free(config);
		error_exit("El fichero esta vacio o faltan datos.\n");
	}
	game->cfg = config;
}

void	start_parser(t_game *game, int argc, char **argv)
{
	int	fd;

	is_valid_argument(argc, argv, true);
	is_valid_file(argv[1], &fd, ".cub", true);
	init_config_parser(game, fd);
}
