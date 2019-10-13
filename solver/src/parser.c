/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** parser file
*/

#include "solver.h"

void display_error(int i)
{
	switch (i) {
		case 1:
			printf("%s\n", "Unable to close the file");
			break;
		case 2:
			printf("%s\n", "Unable to open the file");
			break;
		case 3:
			printf("%s", "no solution found");
			break;
		case 4:
			printf("%s\n", "Error: only X and * are allowed");
			break;
	}
	exit(84);
}

void load_map(solver_t *solv, FILE *fp, char c)
{
	int i = 0;

	solv->map = malloc(sizeof(cell_t *) * (solv->lines * solv->cols + 2));
	if (solv->map == NULL)
		exit(84);
	while ((c = getc(fp)) != EOF) {
		if (c != '\n' && c != 'X' && c != '*')
			display_error(4);
		if (c == 'X')
			solv->map[i] = init_cell(i / solv->cols, \
						i % solv->cols, 0);
		else if (c == '*')
			solv->map[i] = init_cell(i / solv->cols, \
						i % solv->cols, 1);
		if (c != '\n')
			i += 1;
	}
	solv->map[i] = '\0';
	if (solv->map[0]->reachable == 0 || solv->map[i - 1]->reachable == 0)
		display_error(3);
}

void load_file(char c, int x, int y, solver_t *solv)
{
	if (c == 'X')
		vector_add(&(solv->cells), init_cell(y, x, 0));
	else if (c == '*')
		vector_add(&(solv->cells), init_cell(y, x, 1));
}

void parser(solver_t *solv, char *path)
{
	char c;
	char eof;
	FILE *fp = fopen(path, "r");

	if (fp == NULL)
		display_error(2);
	while ((c = getc(fp)) != EOF) {
		eof = c;
		if (c == '\n')
			solv->lines += 1;
		if (solv->lines == 0)
			solv->cols += 1;
	}
	if (eof != '\n')
		solv->lines += 1;
	rewind(fp);
	load_map(solv, fp, 0);
	if (fclose(fp) == EOF)
		display_error(1);
}

solver_t *init_solver(char *path)
{
	solver_t *this = malloc(sizeof(*this));

	if (this == NULL)
		return (NULL);
	this->lines = 0;
	this->cols = 0;
	parser(this, path);
	this->pos_end = this->lines * this->cols;
	return (this);
}
