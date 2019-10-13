/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** header files
*/

#ifndef SOLVER_H_
#define SOLVER_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "vector.h"

typedef struct cell_s {
	int x;
	int y;
	int reachable;
	int closed;
	struct cell_s *parent;
	int g;
	int h;
	int f;
} cell_t;

typedef struct solver_s {
	int lines;
	int cols;
	int pos_end;
	cell_t **map;

	char **array;

	vector_t *cells;
	vector_t *opened;
	vector_t *closed;
	vector_t *adj;
} solver_t;

int solver(char *);
solver_t *init_solver(char *);
int algorithm(solver_t *);
void display_2d(char **, int);
void display_vector(vector_t *);
void display_solver(solver_t *);
int algorithm2(solver_t *);
cell_t *init_cell(int, int, int);
void update_cell(solver_t *, cell_t *, cell_t *);
int is_in_vector(vector_t *, int, int);
int process(solver_t *this);
void get_adjacent_cells(solver_t *this, cell_t *cell);
cell_t *vector_pop_end(vector_t *v);

/* SRC */
void my_putstr(char *);
void my_putchar(char);

#endif /* SOLVER_H_ */
