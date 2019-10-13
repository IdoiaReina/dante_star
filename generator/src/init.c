/*
** EPITECH PROJECT, 2018
** dante
** File description:
** init
*/

#include "generator.h"

Maze *init_maze(char **av)
{
	Maze *maze = (Maze *)malloc(sizeof(Maze));

	if (maze == NULL)
		exit(1);
	maze->room = (Room *)malloc(sizeof(Room));
	if (maze->room == NULL)
		exit(1);
	maze->size_x = atoi(av[1]);
	maze->size_y = atoi(av[2]);
	if (maze->size_x < 1 || maze->size_y < 1) {
		printf ("Wrong Size: Must be two strict positive numbers.\n");
		exit(1);
	}
	maze->av_room = malloc(sizeof(int) * 6);
	reset_av_room(maze);
	init_map(maze);
	maze->x = 0;
	maze-> y = 0;
	return (maze);
}

void init_map(Maze *maze)
{
	int y = 0;
	int x = 0;

	srand(time(NULL));
	maze->map = malloc(sizeof(char *) * (maze->size_y + 1));
	while (y < maze->size_y) {
		maze->map[y] = malloc(sizeof(char) * (maze->size_x + 2));
		y += 1;
	}
	y = 0;
	create_map_double(maze, x, y);
}

void create_map_double(Maze *maze, int x, int y)
{
	while (y < maze->size_y) {
		x = 0;
		while (x < maze->size_x) {
			maze->map[y][x] = ' ';
			x += 2;
		}
		x = 1;
		while (x < maze->size_x) {
			maze->map[y][x] = 'X';
			x += 2;
		}
		maze->map[y][maze->size_x] = '\0';
		y += 2;
	}
	y = 1;
	create_map_x(maze, x, y);
}

void create_map_x(Maze *maze, int x, int y)
{
	while (y < maze->size_y) {
		x = 0;
		while (x < maze->size_x) {
			maze->map[y][x] = 'X';
			x += 1;
		}
		maze->map[y][maze->size_x] = '\0';
		y += 2;
	}
	maze->map[0][0] = '*';
	if (maze->size_x % 2 == 0) {
		maze->map[maze->size_y - 1][maze->size_x - 1] = '*';
		if (maze->size_y % 2 == 0) {
			maze->map[maze->size_y - 2][maze->size_x - 1] = '*';
		}
	}
	if (maze->size_x % 2 != 0 && maze->size_y % 2 == 0)
		maze->map[maze->size_y - 1][maze->size_x - 1] = '*';
}