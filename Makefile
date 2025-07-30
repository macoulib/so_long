# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 19:35:26 by macoulib          #+#    #+#              #
#    Updated: 2025/07/24 20:34:06 by macoulib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -g3 -Wall -Wextra -Werror
SRCS_DIR = ./librairie
UTILS_DIR = ./src
PRINT_DIR = ./monprintfx
MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

# Fichiers sources utils
UTILS = initmap.c parsing.c parsing2.c so_long.c initdata.c rendermap.c movment.c  key_hook.c enemymovment.c utils.c ft_free.c ft_floodfill.c

# Fichiers sources printf
PRINT = ft_printf.c ft_putchar.c ft_puthexamaj.c ft_puthexamin.c ft_putnbr.c ft_putpointer.c ft_putstr.c  ft_putunbr.c 

# Fichiers sources librairie
LIB_SRCS = ft_error.c ft_split.c ft_strchr.c ft_strdup.c ft_strlen.c \
          ft_strrchr.c get_next_line.c ft_strjoin.c ft_strnstr.c tailletableau.c ft_itoa.c ft_calloc.c ft_bzero.c

# Ajout des chemins aux fichiers sources
SRCS = $(addprefix $(UTILS_DIR)/, $(UTILS)) \
       $(addprefix $(SRCS_DIR)/, $(LIB_SRCS)) \
	   $(addprefix $(PRINT_DIR)/, $(PRINT)) 

# Fichiers objets
OBJS = $(SRCS:.c=.o)

STANDARD_FLAGS = -g3 -Wall -Wextra -Werror
LDFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

# Ajout de dépendance vers libmlx.a
$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) $(STANDARD_FLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

# Compilation de libmlx.a si nécessaire
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
