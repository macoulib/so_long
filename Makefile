NAME = so_long
CC = cc
SRCS_DIR = ./src

SRCS = $(addprefix $(SRCS_DIR)/, \
	main.c \
	parsing.c \
	reset.c \
	so_long.c \
	ft_strlen.c \
	ft_strchr.c \
	gnl.c \
	ft_strjoin.c \
)

OBJS = $(SRCS:.c=.o)

STANDARD_FLAGS = -Wall -Werror -Wextra
LDFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
