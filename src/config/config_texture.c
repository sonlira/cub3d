
#include "cub3d.h"

t_texture	parse_texture_type(const char *id)
{
	if (!ft_strcmp(id, "NO"))
		return (TEX_NO);
	if (!ft_strcmp(id, "SO"))
		return (TEX_SO);
	if (!ft_strcmp(id, "WE"))
		return (TEX_WE);
	return (TEX_EA);
}

bool	texture_config(t_config *config, char *line, int *config_count)
{
	int		tex_argc;
	char	**tex_argv;

	tex_argv = ft_split(line, ' ');
	tex_argc = ft_count_elements((const char **) tex_argv);
	if (!validate_texture(config, tex_argc, tex_argv))
	{
		ft_free_split(&tex_argv);
		return (false);
	}
	config->textures[parse_texture_type(tex_argv[0])] = ft_strdup(tex_argv[1]);
	(*config_count)++;
	ft_free_split(&tex_argv);
	return (true);
}
