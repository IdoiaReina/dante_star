/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** algorithm file
*/

#include "solver.h"

int recursiv2(solver_t *solv, int x, int y)
{
	solv->array[x][y] = 'o';
	if (x == (solv->lines - 1) && y == (solv->cols - 1))
		return (1);
	if (x > 0 && solv->array[x - 1][y] == '*' && recursiv2(solv, x - 1, y))
		return (1);
	if (x < solv->cols - 1 && solv->array[x + 1][y] == '*'	\
	&& recursiv2(solv, x + 1, y))
		return (1);
	if (y > 0 && solv->array[x][y - 1] == '*' && recursiv2(solv, x, y - 1))
		return (1);
	if (y < solv->lines - 1 && solv->array[x][y + 1] == '*'	\
	&& recursiv2(solv, x, y + 1))
		return (1);
	solv->array[x][y] = '*';
	return (0);
}

int algorithm(solver_t *solv)
{
	int res = 0;

	res = recursiv2(solv, 0, 0);
	return (res);
}
