NAME = minishell

SRC = main.c utils.c dupenv.c

OBJ = $(SRC:.c=.o)

CC = cc
#-Wall -Wextra -Werror
CFLAGS = #-g -fsanitize=address

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