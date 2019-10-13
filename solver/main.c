/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** main file
*/

#include "solver.h"

int display_help(char *name)
{
	my_putstr("USAGE:\n\t");
	my_putstr(name);
	my_putstr(" [file]\n");
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (84);
	if (av[1][0] == '-' && av[1][1] == 'h')
		return (display_help(av[0]));
	if (solver(av[1]) == 84)
		return (84);
	return (0);
}
