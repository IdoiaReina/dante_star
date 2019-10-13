/*
** EPITECH PROJECT, 2018
** dante
** File description:
** free_maze
*/

#include "generator.h"

void vector_free(vector_t *v)
{
	vector_t *tmp = NULL;
	vector_t *tmp2;

	if (v != NULL)
		tmp = v->next;
	while (tmp) {
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(v);
}

void free_maze(Maze *maze)
{
	int y = 0;

	while (y < maze->size_y) {
		free(maze->map[y]);
		y += 1;
	}
	vector_free(maze->history);
	free(maze->map);
	free(maze->av_room);
	free(maze->room);
	free(maze);
}