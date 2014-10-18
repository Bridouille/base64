##
## Makefile for encrypt in /home/bridou_n/test/colle
## 
## Made by Nicolas Bridoux
## Login   <bridou_n@epitech.net>
## 
## Started on  Tue May 27 18:31:59 2014 Nicolas Bridoux
## Last update Wed May 28 09:02:15 2014 Nicolas Bridoux
##


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
