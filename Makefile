# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 13:04:33 by rofuente          #+#    #+#              #
#    Updated: 2024/07/22 13:03:30 by rofuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC_PATH = ./src
UTIL_PATH = ./utils
OBJ_DIR = obj

CC = gcc
DEBUG = -g3 -fsanitize=address
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all
CFLAGS = -Wall -Werror -Wextra
MINILIBX = -lXext -lX11 -lm -D LINUX
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx_Linux.a

LIB = ./include/cub3d.h

SRC = ft_cub.c ft_read_map.c ft_check_map.c ft_start_xpm.c ft_player.c ft_init_player.c ft_key.c
UTIL = ft_no_nl.c ft_slen.c freezer.c

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o) $(UTIL:%.c=%.o))

##########COLORES##########
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

##########REGLAS##########
all: make_libft make_mlx $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
$(OBJ_DIR)/%.o: $(UTIL_PATH)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

make_libft:
	@make all -sC ./libft

make_mlx:
	@make -C ./mlx

$(NAME): $(OBJ)
	@$(CC) $(DEBUG) $(CFLAGS) $(OBJ) -I $(LIB) $(LIBFT) $(MLX) $(MINILIBX) -o $(NAME)
	@clear
	@echo "\n$(G)Cub3D compiled!$(DEF_COLOR)-> $@\n"

clean:
	@rm -f $(OBJ)
	@make clean -sC ./libft
	@make clean -sC ./mlx
	@rm -rf $(OBJ_DIR)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC ./libft
	@make clean -sC ./mlx
	@rm -rf $(OBJ_DIR)
	@clear
	@echo "$(R)All program .o and files removed$(DEF_COLOR)\n"

re: fclean all

.PHONY:		all clean fclean re
