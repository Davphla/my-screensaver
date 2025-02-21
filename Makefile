##
## EPITECH PROJECT, 2020
## makefile
## File description:
## gcc etc...
##

CFLAGS = -Wall -Wextra -g3 -I./include -l csfml-graphics -lm -l csfml-system

LIBS = -L./lib -lfml -L./lib -lmy

SRC	=	main.c \
		main_window.c \
		struct/initialize.c \
		struct/destroy.c \
		resources/effect_1.c \
		resources/effect_2.c \
		resources/effect_3.c \

OBJ 	=	$(SRC:.c=.o)

NAME	=	my_screensaver

all:	$(NAME)

$(NAME):	$(OBJ)
		@make -C ./lib/fml
		@make -C ./lib/my
		@gcc -o $(NAME) $(SRC) $(CFLAGS) $(LIBS)

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/fml
	make fclean -C ./lib/my

re: fclean all
