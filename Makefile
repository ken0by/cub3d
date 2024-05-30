# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 13:04:33 by rofuente          #+#    #+#              #
#    Updated: 2024/05/30 14:56:55 by rofuente         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# LIB	=	ar rcs
# RM	=	rm -f

# CC	=	gcc
# CFLAGS	=	-Wall -Wextra -Werror
# INC	=	-I ./include -I ./libft/include/ -I ./mlx
# MiniLibX	=	./mlx/libmlx.a
# #MLX_casa	=	./mlx/libmlx_Darwin.a
# MLX_FLAGS	=	-lXext -lX11 -lm -L/usr/X11R6/lib -D LINUX
# DEBUG	=	-g3 -fsanitize=address

# NAME	=	cub3D

# SRC	=	ft_cub.c

# SRC_DIR	=	./src/

# OBJ_DIR	=	./obj/
# OBJ_FILES	=	$(SS:.c=.o)
# OBJ	=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

# LIBFT_PATH = libft/
# LIBFT = $(LIBFT_PATH)libft.a

# MLX_PATH = ./mlx/
# MLX = $(MLX_PATH)libmlx_Linux.a

# ##########COLORES##########
# DEF_COLOR = \033[0;39m
# CUT = \033[K
# R = \033[31;1m
# G = \033[32;1m
# Y = \033[33;1m
# B = \033[34;1m
# P = \033[35;1m
# GR = \033[30;1m
# END = \033[0m

# ##########REGLAS##########
# all: $(OBJ_DIR) $(NAME)

# $(LIBFT) : $(LIBFT_PATH)
# 	@make -sC $(LIBFT_PATH)

# $(MLX) : $(MLX_PATH)
# 	@make -sC $(MLX_PATH)

# $(OBJ_DIR):
# 	@mkdir -p $(OBJ_DIR)
# $(OBJ_DIR)%.o:$(SRC_DIR)%.c
# 	@$(CC) $(CFLAGS) -c $< -o $@

# $(NAME): $(OBJ) $(LIBFT) $(MLX)
# 	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIBFT) $(MiniLibX) $(MLX_FLAGS) -o $(NAME)
# 	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

# clean:
# 	@$(RM) $(OBJ)
# 	@make clean -sC $(LIBFT_PATH)
# 	@make clean -sC $(MLX_PATH)
# 	@rm -rf $(OBJ_DIR)
# 	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

# fclean: clean
# 	@$(RM) $(NAME)
# 	@echo "$(R)Program file removed$(DEF_COLOR)\n"

# re: fclean all

# .PHONY: all clean fclean re




NAME = cub3D
SRC_PATH = ./src
DOT_O = _Objfiles

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address
MINILIBX = -lXext -lX11 -lm -D LINUX
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx_Linux.a

LIB = ./include/cub3d.h

SRC = ft_cub.c

OBJ = $(addprefix $(DOT_O)/, $(SRC:%.c=%.o))

all: make_libft make_mlx $(DOT_O) $(NAME)

$(DOT_O):
	mkdir -p $(DOT_O)

$(DOT_O)/%.o: $(SRC_PATH)/%.c | $(DOT_O)
	$(PURPLE) COMPILING MINISHELL... $(RESET)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

make_libft:
	@make all -sC ./libft

make_mlx:
	@make -C ./mlx

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -I $(LIB) $(LIBFT) $(MLX) $(MINILIBX) -o $(NAME)
	$(GREEN)
	@clear
	@echo "CUB3D READY!"
	@echo $(RESET)

clean:
	$(CYAN) "\n cleaning everything...\n" $(RESET)
	@rm -f $(OBJ)
	@make clean -sC ./libft
	@make clean -C ./mlx
	@rm -rf $(DOT_O)

fclean: clean
	@clear
	@rm -f $(NAME)
	@make fclean -sC ./libft
	@make clean -C ./mlx
	@rm -rf $(DOT_O)

re: fclean all

GREEN 	= @echo "\033[0;32m"
BLUE 	= @echo "\033[0;34m"
PURPLE 	= @echo "\033[0;35m"
CYAN 	= @echo "\033[0;36m"
YELLOW = \033[0;93m
RESET 	= "\033[1;0m"

.PHONY:		all clean fclean re
