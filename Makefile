
SRCS	=	main.c			\

NAME	= 	coucou

OBJS	=	$(SRCS:.c=.o)

CC	= 	gcc

CFLAGS	= 	-Wall -Wextra -O2

RM	=	rm -f


$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
