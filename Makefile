NAME = push_swap

SRCS = check.c free.c ft_split.c instruction1.c instruction2.c list.c push_swap.c utils.c utils2.c presort.c sort.c radix.c

OBJS  = $(SRCS:.c=.o)

HEADER_FILE = push_swap.h

CC = cc
CFLAG = -Wall -Wextra -Werror -Wunreachable-code

all: $(NAME)

$(NAME): norm $(OBJS)
		$(CC) $(CFLAG) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER_FILE)
		$(CC) -c $(CFLAG) $< -o $@

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re: fclean all

norm :
	norminette $(SRCS) $(HEADER_FILE)

.PHONY: all clean fclean re norm
