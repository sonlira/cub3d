NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude #-g -g3

# Directorios
INC_DIR		= include
OBJ_DIR		= obj
SRC_DIR		= src
LIB_DIR		= lib
# ENV_DIR		= $(SRC_DIR)/env
# BUILTIN_DIR	= $(SRC_DIR)/builtin
# EXEC_DIR	= $(SRC_DIR)/executor
# PARSER_DIR	= $(SRC_DIR)/parser
# VALIDS_DIR	= $(PARSER_DIR)/validators
# SIGNALS_DIR	= $(SRC_DIR)/signals
# UTILS_DIR	= $(SRC_DIR)/utils


# Contenedio de cada directorio sin su extencion
# BUILTIN		= dispatcher ft_cd ft_echo ft_env ft_exit ft_export ft_pwd ft_unset
# ENV			= ft_copy_env ft_free_env ft_get_env_value ft_print_env ft_print_sorted_env ft_set_env_var ft_unset_env_var ft_env_shlvl
# EXECUTOR	= cmd_executor command_fds executor execvp forks pipes process_heredocs handle_heredoc
# PARSER		= expander format_input parser rm_quotes_and_bslash split_ignoring_quotes split_valid_semicolons command_check arg_processing
# VALIDATORS	= delimiters quotes redirection
# SIGNALS		= signals
# UTILS		= array_utils matrix_utils struct_free struct_init
# SRC			= minishell

# Libft
LIBFT_DIR	= $(LIB_DIR)/libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

# Mlx
MLX_DIR		= $(LIB_DIR)/minilibx-linux
MLX_A			= $(MLX_DIR)/libmlx.a

# Necesario para que funcione minilibx
LIBS 		= -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -lXrender -lm -lbsd

# SRCS		= $(addsuffix .c, $(addprefix $(BUILTIN_DIR)/, $(BUILTIN))) \
# 			$(addsuffix .c, $(addprefix $(ENV_DIR)/, $(ENV))) \
# 			$(addsuffix .c, $(addprefix $(EXEC_DIR)/, $(EXECUTOR))) \
# 			$(addsuffix .c, $(addprefix $(PARSER_DIR)/, $(PARSER))) \
# 			$(addsuffix .c, $(addprefix $(VALIDS_DIR)/, $(VALIDATORS))) \
# 			$(addsuffix .c, $(addprefix $(SIGNALS_DIR)/, $(SIGNALS))) \
# 			$(addsuffix .c, $(addprefix $(UTILS_DIR)/, $(UTILS))) \
# 			$(addsuffix .c, $(addprefix $(SRC_DIR)/, $(SRC))) \
			
# Encuentra todos los archivos .c en src/ y subcarpetas 
# Reemplazar una vez terminado el proyecto (no está permitido 😞)
SRCS		= $(shell find $(SRC_DIR) -name "*.c")

OBJS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(MLX_A) $(LIBFT_A) $(NAME)

$(MLX_A):
	@echo "📚 Compilando minilibx..."
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT_A):
	@echo "📚 Compilando libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
	@echo "✅ Compilación completa."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🛠️  Compilando $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "🧹 Objetos eliminados."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "🧨 Binario eliminado."

norm:
	@echo "Checking norminette..."
	@OUTPUT=$$(norminette $(SRC_DIR)/ $(INC_DIR)/ $(LIBFT_DIR)/); \
	echo "$$OUTPUT" | grep -v "OK!" || true; \
	if echo "$$OUTPUT" | grep -q "Error:"; then \
		echo "❌ Norminette found errors."; \
	else \
		echo "✅ Norma OK!"; \
	fi

re: fclean all

.PHONY: all clean fclean re