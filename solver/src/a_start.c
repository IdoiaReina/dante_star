/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** algorithm file
*/

#include "solver.h"

void get_adjacent_cells(solver_t *this, cell_t *cell)
{
	if (cell->x < this->lines - 1)
		vector_add(&(this->adj), this->map[(cell->x + 1)	\
				* this->cols + cell->y]);
	if (cell->y > 0)
		vector_add(&(this->adj), this->map[cell->x		\
				* this->cols + cell->y - 1]);
	if (cell->x > 0)
		vector_add(&(this->adj), this->map[(cell->x - 1)	\
				* this->cols + cell->y]);
	if (cell->y < this->cols - 1)
		vector_add(&(this->adj), this->map[cell->x		\
				* this->cols + cell->y + 1]);
}

cell_t *vector_pop_end(vector_t *v)
{
	vector_t *tmp = v;
	vector_t *tmp2;
	cell_t *ret = NULL;

	if (tmp->next != NULL)
		tmp2 = tmp;
	while (tmp->next) {
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = NULL;
	ret = tmp->item;
	free(tmp);
	return (ret);
}

int algorithm2(solver_t *this)
{
	int res = 0;

	this->opened = vector_init();
	this->closed = vector_init();
	this->adj = vector_init();
	res = process(this);
	return (res);
}