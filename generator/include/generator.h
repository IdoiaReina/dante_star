/*
** EPITECH PROJECT, 2018
** DANTE
** File description:
** header files
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "vector.h"

typedef struct s_Rooms
{
	int x_m;
	int x_p;
	int y_m;
	int y_p;
}Room;

typedef struct s_Entities
{
	int *av_room;
	Room *room;
	char **map;
	int size_y;
	int size_x;
	int x;
	int y;
	vector_t *history;
}Maze;

/*USAGE*/
void usage(void);

/*INIT*/
Maze *init_maze(char **av);
void init_map(Maze *maze);
void create_map_double(Maze *maze, int x, int y);
void create_map_x(Maze *maze, int x, int y);
void reset_av_room(Maze *maze);

/*FREE*/
void free_maze(Maze *maze);

/*PRINT MAP*/
void print_maze(Maze *maze);

/*GENERATE MAZE*/
int rand_number(int b);
void generate_maze(Maze *maze);

/*CHECK_ROOMS*/
void verif_x(Maze *maze, int i);
void verif_y(Maze *maze, int i);
void check_rooms(Maze *maz);
void which_av_room(Maze *maze, int y, int x);
int check_available_room(Maze *maze, int room_y, int room_x);

/*MINE ROOMS*/
void mine_rooms(Maze *maze);
void switch_star(Maze *maze, int room);
void create_imperfect(Maze *maze);

/*LILLIB*/
void my_putstr(char *str);
int my_str_compare(char *src, char *to_compare);

#endif /* GENERATOR_H_ */