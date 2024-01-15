NAME = minishell

SRC = main.c utils.c dupenv.c

OBJ = $(SRC:.c=.o)

CC = cc
#-Wall -Wextra -Werror
CFLAGS = #-g -fsanitize=address

LIBFT = ./libft_42/libft/libft.a

RM = rm -f

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJ)
		make -C ./libft_42/libft
		$(CC) $(CFLAFS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	make clean -C ./libft_42/libft
	$(RM) $(OBJ)

fclean:clean
	make fclean -C ./libft_42/libft
	$(RM) $(NAME)

re: fclean all