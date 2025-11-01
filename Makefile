# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME		= cub3d
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CFLAGS		+= -Iinclude -Ilib/libft/include -Ilib/minilibx-linux

# Directorios
INC_DIR		= include
OBJ_DIR		= obj
SRC_DIR		= src
LIB_DIR		= lib

# Librerías
LIBFT_DIR	= $(LIB_DIR)/libft
LIBFT_A		= $(LIBFT_DIR)/lib42.a

MLX_DIR		= $(LIB_DIR)/minilibx-linux
MLX_A		= $(MLX_DIR)/libmlx.a

LIBS 		= -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -l42 -lXext -lX11 -lXrender -lm -lbsd

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS		= $(shell find $(SRC_DIR) -name "*.c")
OBJS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
COUNT		= $(words $(SRCS))
INDEX		= 0

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
RED			:= \033[0;31m
CYAN		:= \033[0;36m
PURPLE		:= \033[0;35m
RESET		:= \033[0m

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(MLX_A) $(LIBFT_A) $(OBJS)
	@printf "\n$(PURPLE)→ Compilando $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@printf "$(GREEN)✔ Compilación completa.$(RESET)\n"

# Compilación dinámica en una sola línea
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))
	@printf "\r$(CYAN)Compilando [$(INDEX)/$(COUNT)]: $(notdir $<)$(RESET)"
	@tput el
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	@echo "$(YELLOW)Compilando libft...$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR)

$(MLX_A):
	@echo "$(YELLOW)Compilando minilibx...$(RESET)"
	@$(MAKE) -s -C $(MLX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -s -C $(MLX_DIR)
	@$(MAKE) clean -s -C $(LIBFT_DIR)
	@echo "$(RED)✔ Objetos eliminados.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -s -C $(LIBFT_DIR)
	@echo "$(RED)✔ Binario eliminado.$(RESET)"

norm:
	@echo "$(CYAN)Revisando norminette...$(RESET)"
	@OUTPUT=$$(norminette $(SRC_DIR)/ $(INC_DIR)/ $(LIBFT_DIR)/); \
	echo "$$OUTPUT" | grep -v "OK!" || true; \
	if echo "$$OUTPUT" | grep -q "Error:"; then \
		echo "$(RED)Norminette encontró errores.$(RESET)"; \
	else \
		echo "$(GREEN)Norma OK.$(RESET)"; \
	fi

re: fclean all

.PHONY: all clean fclean re norm
