# Makefile

NAME = snake

SRCS = main.c createmap.c Chaine.c game.c sdl.c

all :  $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME) -I/opt/homebrew/include -L/opt/homebrew/lib -lSDL2 -lSDL2_image -lSDL2_ttf

fclean:
	rm -f $(NAME)

re: fclean all
