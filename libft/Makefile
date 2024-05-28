LIB = ar rcs
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./include -I ./ft_printf/include -I ./gnl/include

NAME = libft.a

FT	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_split.c ft_tolower.c ft_toupper.c
LST	=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
MEM	=	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
PUT	=	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
STR	=	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c
FT_PRINTF	=	ft_printf.c ft_print_char.c ft_print_nbr.c
GNL	=	get_next_line.c get_next_line_utils.c


SRC1_DIR	=	./ft/
SRC2_DIR	=	./lst/
SRC3_DIR	=	./mem/
SRC4_DIR	=	./put/
SRC5_DIR	=	./str/
SRC6_DIR	=	./ft_printf/src/
SRC7_DIR	=	./gnl/src/

OBJ_DIR	=	./obj/
OBJ_FILES	=	$(FT:.c=.o) $(LST:.c=.o) $(MEM:.c=.o) $(PUT:.c=.o) $(STR:.c=.o) $(FT_PRINTF:.c=.o) $(GNL:.c=.o)
OBJ	=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

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

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC1_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_DIR)%.o:$(SRC2_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_DIR)%.o:$(SRC3_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_DIR)%.o:$(SRC4_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_DIR)%.o:$(SRC5_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_DIR)%.o:$(SRC6_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_DIR)%.o:$(SRC7_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@$(LIB) $(NAME) $(OBJ)
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

clean:
	$(RM) $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(R)All .o library files removed$(DEF_COLOR)\n"

fclean: clean
	$(RM) $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "$(R)Library .a library file removed$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
