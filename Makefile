NAME = minishell

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
		$(CC) $(CFLAFS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)

re: fclean all