/*
** EPITECH PROJECT, 2018
** dante
** File description:
** print
*/

#include "generator.h"

void print_maze(Maze *maze)
{
	int y = 0;

	while (y < maze->size_y - 2) {
		printf("%s\n", maze->map[y]);
		y += 1;
	}
	printf("%s\n%s", maze->map[y], maze->map[y + 1]);
}