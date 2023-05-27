##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC	=	$(shell find src -type f -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

RM	=	rm -f

all:	$(NAME)

$(NAME):
	make -C lib/my
	gcc -g3 $(SRC) -o bsq -W -Wall -Wextra -Llib/my -lmy -Iinclude
	rm lib/libmy.a
	rm lib/my/libmy.a
	make clean

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
