#Makefile 

NAME = sokaban

SRCS = main.c \
	plateau.c \
	move.c

all :  $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all