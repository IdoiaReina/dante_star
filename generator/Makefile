##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

SRC	=	src/main.c				\
		src/usage.c 				\
		src/init.c 				\
		src/print_map.c 			\
		lillib/my_putstr.c 			\
		lillib/my_str_compare.c 		\
		src/generate_maze.c 			\
		src/check_rooms.c 			\
		src/mine_rooms.c 			\
		src/vector/vectori.c 			\
		src/free_maze.c 			\


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include

CFLAGS	+=	-Wall -Wextra -o3

NAME	=	generator

all:		$(NAME) clean

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
