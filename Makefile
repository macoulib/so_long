NAME = so_long
CC = cc
SRCS_DIR = ./librairie
UTILS_DIR = ./src

# Fichiers sources utils
UTILS = initmap.c parsing.c so_long.c

# Fichiers sources librairie
LIB_SRCS = ft_error.c ft_split.c ft_strchr.c ft_strdup.c ft_strlen.c \
          ft_strrchr.c get_next_line.c ft_strjoin.c ft_strnstr.c tailletableau.c

# Ajout des chemins aux fichiers sources
SRCS = $(addprefix $(UTILS_DIR)/, $(UTILS)) \
       $(addprefix $(SRCS_DIR)/, $(LIB_SRCS))

# Fichiers objets
OBJS = $(SRCS:.c=.o)

STANDARD_FLAGS = -Wall -Werror -Wextra
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(STANDARD_FLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
