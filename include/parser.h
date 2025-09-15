
#ifndef PARSER_H
# define PARSER_H

void	start_parser(t_game *game, int argc, char **args);

bool	is_valid_argc(int argc, bool quit);
bool	is_valid_args(char **args, bool quit);
bool	is_valid_argument(int argc, char **args, bool quit);

bool	is_valid_extension(char *file_path, char *file_extension, bool quit);
bool	open_file(char *file, int *fd, bool quit);
bool	is_valid_file(char *file, int *fd, char *extension, bool quit);

#endif