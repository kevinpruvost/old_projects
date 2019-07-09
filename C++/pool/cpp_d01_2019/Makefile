##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	= menger

CC	= gcc

RM	= rm -f

SRCS	= 	main.c 						\
			menger.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/

CFLAGS += -Wall -Wextra -g

all: $(NAME)

$(NAME):
	 @$(CC) $(SRCS) -o $(NAME) $(CFLAGS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

test: 	all
	@./$(NAME)
