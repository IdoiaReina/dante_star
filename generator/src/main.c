/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** main file
*/

#include "generator.h"

int main(int ac, char **av)
{
	Maze *maze;

	if (ac < 3 || ac > 4)
		usage();
	maze = init_maze(av);
	maze->history = vector_init();
	generate_maze(maze);
	if (ac < 4)
		create_imperfect(maze);
	if (ac == 4 && my_str_compare(av[3], "perfect") == 1)
		create_imperfect(maze);
	print_maze(maze);
	free_maze(maze);
	return (0);
}