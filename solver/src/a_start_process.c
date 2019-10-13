/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** algorithm file
*/

#include "solver.h"

void process_adj_is_in_vector(solver_t *this, cell_t *cell, cell_t *adj_cell)
{
	if (is_in_vector(this->opened, adj_cell->x, adj_cell->y) == 1) {
		if (adj_cell->g > (cell->g + 10))
			update_cell(this, adj_cell, cell);
	}
	else {
		update_cell(this, adj_cell, cell);
		vector_add(&(this->opened), adj_cell);
	}
}

void process_adj(solver_t *this, cell_t *cell, cell_t *adj_cell)
{
	vector_t *adj_cells;

	get_adjacent_cells(this, cell);
	adj_cells = this->adj->next;
	while (adj_cells) {
		adj_cell = adj_cells->item;
		if (adj_cell->reachable == 1 && this->map[adj_cell->x *	\
		this->cols + adj_cell->y]->closed == 0)
			process_adj_is_in_vector(this, cell, adj_cell);
		adj_cells = adj_cells->next;
	}
}

int process(solver_t *this)
{
	cell_t *cell = NULL;

	vector_add(&(this->opened), this->map[0]);
	while (vector_total(this->opened)) {
		cell = vector_pop_end(this->opened);
		this->map[cell->x * this->cols + cell->y]->closed = 1;
		if (cell->x == this->lines - 1 && cell->y == this->cols - 1)
			return (1);
		process_adj(this, cell, NULL);
		vector_free3(&(this->adj));
	}
	return (0);
}