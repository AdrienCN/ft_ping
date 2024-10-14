SRCS = srcs/ft_ping.c

OBJ = $(SRCS:.c=.o)

NAME = myping

CC = gcc 

CFLAGS = -Wall -Werror -Wextra


.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all