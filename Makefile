# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macoulib <macoulib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 19:35:26 by macoulib          #+#    #+#              #
#    Updated: 2025/07/10 13:24:19 by macoulib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = so_long
CC = cc -g3
SRCS_DIR = ./librairie
UTILS_DIR = ./src
PRINT_DIR = ./ftprint

# Fichiers sources utils
UTILS = initmap.c parsing.c so_long.c initdata.c rendermap.c movment.c  key_hook.c enemymovment.c utils.c ft_free.c

# Fichiers sources utils
PRINT = ft_printf.c ft_putchar.c ft_puthexamaj.c ft_puthexamin.c ft_putnbr.c ft_putpointer.c ft_putstr.c  ft_putunbr.c 

# Fichiers sources librairie
LIB_SRCS = ft_error.c ft_split.c ft_strchr.c ft_strdup.c ft_strlen.c \
          ft_strrchr.c get_next_line.c ft_strjoin.c ft_strnstr.c tailletableau.c ft_itoa.c

# Ajout des chemins aux fichiers sources
SRCS = $(addprefix $(UTILS_DIR)/, $(UTILS)) \
       $(addprefix $(SRCS_DIR)/, $(LIB_SRCS)) \
	   $(addprefix $(PRINT_DIR)/, $(PRINT)) 

# Fichiers objets
OBJS = $(SRCS:.c=.o)

STANDARD_FLAGS = -g3
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(STANDARD_FLAGS) $(OBJS) -o $(NAME) $(LDFLAGS) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
