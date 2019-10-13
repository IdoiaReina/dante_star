/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** solver file
*/

#include "solver.h"

void free_solver(solver_t *solv)
{
	int i = 0;

	while (solv->map[i]) {
		free(solv->map[i]);
		i += 1;
	}
	vector_free2(solv->opened);
	vector_free2(solv->closed);
	vector_free2(solv->adj);
	free(solv->map);
	free(solv->opened);
	free(solv->closed);
	free(solv->adj);
	free(solv);
}

int solver(char *path)
{
	solver_t *solv = init_solver(path);

	if (algorithm2(solv) == 0) {
		my_putstr("no solution found");
		return (84);
	}
	display_solver(solv);
	free_solver(solv);
	return (0);
}
