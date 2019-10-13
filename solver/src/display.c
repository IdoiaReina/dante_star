/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** display file
*/

#include "solver.h"

void display_path(solver_t *this)
{
	cell_t *start = this->map[0];
	cell_t *cell = this->map[this->cols - 1 +	\
		(this->cols * (this->lines - 1))];

	printf("NUM = %d\n", this->cols - 1 + (this->cols * (this->lines - 1)));
	printf("path: cell: %d, %d\n", cell->x, cell->y);
	while (cell->parent->x != start->x || cell->parent->y != start->y) {
		cell = cell->parent;
		printf("path: cell: %d, %d\n", cell->x, cell->y);
	}
}

void display_vector(vector_t *v)
{
	vector_t *tmp = v->next;
	cell_t *cell;

	while (tmp) {
		cell = tmp->item;
		printf("VECTOR X = %d Y = %d R = %d\n", cell->x, \
						cell->y, \
						cell->reachable);
		tmp = tmp->next;
	}
}

void display_2d(char **tab, int width)
{
	int x = 0;
	int y = 0;

	while (tab[x]) {
		y = 0;
		while (y < width) {
			printf("%c", tab[x][y]);
			y += 1;
		}
		printf("%c", '\n');
		x += 1;
	}
}

void set_path(solver_t *this)
{
	cell_t *start = this->map[0];
	cell_t *cell = this->map[this->cols * this->lines - 1];

	this->map[0]->reachable = 2;
	while (cell->parent->x != start->x || cell->parent->y != start->y) {
		this->map[cell->x * this->cols + cell->y]->reachable = 2;
		cell = cell->parent;
	}
	this->map[cell->x * this->cols + cell->y]->reachable = 2;
}

void display_solver(solver_t *this)
{
	int x = 0;

	set_path(this);
	while (this->map[x]) {
		if (x % this->cols == 0 && x > this->cols - 1)
			printf("%c", '\n');
		if (this->map[x]->reachable == 2)
			printf("%c", 'o');
		else if (this->map[x]->reachable == 0)
			printf("%c", 'X');
		else if (this->map[x]->reachable == 1)
			printf("%c", '*');
		x += 1;
	}
}
