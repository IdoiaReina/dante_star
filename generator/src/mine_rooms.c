/*
** EPITECH PROJECT, 2018
** dante
** File description:
** mine_rooms
*/

#include "generator.h"

void mine_rooms(Maze *maze)
{
	int randnb = rand_number(maze->av_room[0]);
	int cell_of_avroom = 1;
	int cell_ready = 0;

	while (cell_ready < randnb) {
		if (maze->av_room[cell_of_avroom] != 0)
			cell_ready += 1;
		cell_of_avroom += 1;
	}
	cell_of_avroom -= 1;
	switch_star(maze, cell_of_avroom);
}

void switch_star(Maze *maze, int which_room)
{
	int i = 1;
	int j = -1;

	switch (which_room) {
	case 1:
		while (i <= maze->room->x_p) {
			maze->map[maze->y][maze->x + i] = '*';
			i += 1;
		}
		vector_add(&(maze->history), maze->x);
		vector_add(&maze->history, maze->y);
		maze->x += maze->room->x_p;
		break;
	case 2:
		while (j >= maze->room->x_m) {
			maze->map[maze->y][maze->x + j] = '*';
			j -= 1;
		}
		vector_add(&(maze->history), maze->x);
		vector_add(&maze->history, maze->y);
		maze->x += maze->room->x_m;
		break;
	case 3:
		while (i <= maze->room->y_p) {
			maze->map[maze->y + i][maze->x] = '*';
			i += 1;
		}
		vector_add(&maze->history, maze->x);
		vector_add(&(maze->history), maze->y);
		maze->y += maze->room->y_p;
		break;
	case 4:
		while (j >= maze->room->y_m) {
			maze->map[maze->y + j][maze->x] = '*';
			j -= 1;
		}
		vector_add(&maze->history, maze->x);
		vector_add(&(maze->history), maze->y);
		maze->y += maze->room->y_m;
		break;
	}
}

void detect_wall_x(Maze *maze, int y)
{
	int x = 0;
	int randnb = rand_number(7);

	while (x < maze->size_x) {
		if (maze->map[y][x] == 'X' && randnb == 2)
			maze->map[y][x] = '*';
		x += 1;
		randnb = rand_number(7);
	}
}

void create_imperfect(Maze *maze)
{
	int y = 0;

	while (y < maze->size_y) {
		detect_wall_x(maze, y);
		y += 1;
	}
}