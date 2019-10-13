##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc -g

RM	=	rm -f

SRC	=	main.c			\
		src/solver.c		\
		src/solver_src.c	\
		src/recursiv.c		\
		src/parser.c		\
		src/display.c		\
		src/vector/vector.c	\
		src/vector/vector2.c	\
		src/a_start.c		\
		src/a_start_src.c	\
		src/a_start_process.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

CFLAGS	+=	-Wall -Wextra

NAME	=	solver

all:		$(NAME) clean

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:
		$(RM) $(NAME)

re:		fclean all clean

.PHONY:		all clean fclean re
