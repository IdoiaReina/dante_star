##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

RM	=	rm -f

all:		install
		cp ../generator/generator ../solver/solver .

install:
		(cd ../solver; make)
		(cd ../generator; make)

clean:


fclean:		clean
		$(RM) generator solver

re:		fclean all

.PHONY:		all clean fclean re
