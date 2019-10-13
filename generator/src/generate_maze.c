/*
** EPITECH PROJECT, 2018
** dante
** File description:
** generate_maze
*/

#include "generator.h"

int rand_number(int b)
{
	int random = 0;

	random = rand() % (b % 10) + 1;
	return (random);
}

void reset_av_room(Maze *maze)
{
	free(maze->av_room);
	maze->av_room = malloc(sizeof(int) * 6);
	maze->av_room[0] = 0;
	maze->av_room[1] = 0;
	maze->av_room[2] = 0;
	maze->av_room[3] = 0;
	maze->av_room[4] = 0;
	maze->av_room[5] = 0;
}

int the_end_x(Maze *maze, int y)
{
	int x = 0;

	while (x < maze->size_x) {
		if (maze->map[y][x] == ' ')
			return (1);
		x += 1;
	}
	return (0);
}

int the_end(Maze *maze)
{
	int y = 0;

	while (y < maze->size_y) {
		if (the_end_x(maze, y) == 1)
			return (1);
		y += 1;
	}
	return (0);
}

void generate_maze(Maze *maze)
{
	while (the_end(maze) != 0) {
		check_rooms(maze);
		if (maze->av_room[0] != 0)
			mine_rooms(maze);
		else {
			maze->y = vector_pop_end(&maze->history);
			maze->x = vector_pop_end(&maze->history);
		}
		reset_av_room(maze);
	}
}