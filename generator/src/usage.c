/*
** EPITECH PROJECT, 2018
** dante
** File description:
** usage
*/

#include "generator.h"

void usage(void)
{
	my_putstr("USAGE\n\t./generator x y [perfect]");
	my_putstr("\nDESCRIPTION\n\tx y : size of the maze.");
	my_putstr("\n\t[perfect]: As the perfect argument is optional, ");
	my_putstr("\n\tthe default generation will be an imperfect maze.\n");
	exit(0);
}