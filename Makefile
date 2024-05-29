# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodro <rodro@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/28 13:04:33 by rofuente          #+#    #+#              #
#    Updated: 2024/05/29 16:51:13 by rodro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB	=	ar rcs
RM	=	rm -f

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I ./include -I ./libft/include/ -I ./mlx2
#MiniLibX	=	./mlx2/libmlx_Linux.a
MLX_casa	=	./mlx2/libmlx_Darwin.a
MLX_FLAGS	=	-lXext -lX11 -lm -L/usr/X11R6/lib
DEBUG	=	-g3 -fsanitize=address

NAME	=	cub3D

SRC	=	ft_cub.c

SRC_DIR	=	./src/

OBJ_DIR	=	./obj/
OBJ_FILES	=	$(SS:.c=.o)
OBJ	=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = mlx2/
MLX = $(MLX_PATH)libmlx_Linux.a

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
all: $(OBJ_DIR) $(NAME)

$(LIBFT) : $(LIBFT_PATH)
	@make -sC $(LIBFT_PATH)

$(MLX) : $(MLX_PATH)
	@make -sC $(MLX_PATH)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_casa) $(MLX_FLAGS) -o $(NAME)
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

clean:
	@$(RM) $(OBJ)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(MLX_PATH)
	@rm -rf $(OBJ_DIR)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(R)Program file removed$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
