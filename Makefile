NAME = push_swap

SRCS = check.c free.c ft_split.c instruction1.c instruction2.c instruction3.c list.c push_swap.c utils.c utils2.c

OBJS  = $(SRCS:.c=.o)



CC = cc
# CFLAG = -Wall -Wextra -Werror -Wunreachable-code
CFLAG = -g

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER_FILE)
		$(CC) -c $(CFLAG) $^ -o $@

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
