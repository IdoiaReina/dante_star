/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** src file
*/

#include "solver.h"

void my_putstr(char *str)
{
	int i = 0;

	while (str[i]) {
		my_putchar(str[i]);
		i += 1;
	}
}

void my_putchar(char c)
{
	write(1, &c, 1);
}
