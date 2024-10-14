SRCS = srcs/ft_ping

OBJ = $(SRCS:.c=.o)

NAME = myping

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I 


.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBS_PATH) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ./minishell.log

re: fclean all