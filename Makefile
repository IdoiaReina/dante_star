##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

all:		install clean

install:
		(cd solver; make all)
		(cd generator; make all)
		(cd tournament; make all)

clean:
		(cd solver; make clean)
		(cd generator; make clean)
		(cd tournament; make clean)

fclean:		clean
		(cd solver; make fclean)
		(cd generator; make fclean)
		(cd tournament; make fclean)

re:		fclean all

.PHONY:		all clean fclean re
