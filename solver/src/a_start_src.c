/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** algorithm file
*/

#include "solver.h"

cell_t *init_cell(int x, int y, int reachable)
{
	cell_t *this =  malloc(sizeof(*this));

	if (this == NULL)
		return (NULL);
	this->x = x;
	this->y = y;
	this->reachable = reachable;
	this->parent = NULL;
	this->g = 0;
	this->h = 0;
	this->f = 0;
	this->closed = 0;
	return (this);
}

int my_abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int get_heuristic(solver_t *this, int x, int y)
{
	return (10 * (my_abs(x - this->lines) + my_abs(y - this->cols)));
}

void update_cell(solver_t *this, cell_t *adj, cell_t *cell)
{
	adj->g = cell->g + 10;
	adj->h = get_heuristic(this, adj->x, adj->y);
	adj->parent = cell;
	adj->f = adj->g + adj->h;
}

int is_in_vector(vector_t *v, int x, int y)
{
	vector_t *tmp = v->next;
	cell_t *cell_v = NULL;

	while (tmp) {
		cell_v = tmp->item;
		if (cell_v->x == x && cell_v->y == y)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
