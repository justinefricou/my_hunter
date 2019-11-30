##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## A Makefile that compiles cat
##

NAME	=	my_hunter

SRC	=	main.c\
		display_usage.c\
		play.c\
		events_play.c\
		pigeon.c\
		background.c\
		weapon.c

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:	fclean all