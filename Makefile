SRCS = 						\
	srcs/ft_ping.c 			\
	srcs/ft_ping_parsing.c	\
	srcs/ft_signal.c

OBJ = $(SRCS:.c=.o)

NAME = myping

CC = gcc 

#DEBUG
CFLAGS = -Wall -Werror -Wextra -std=c99 -g

#CFLAGS = -Wall -Werror -Wextra -std=c99 -g



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