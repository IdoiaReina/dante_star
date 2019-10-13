/*
** EPITECH PROJECT, 2018
** dante
** File description:
** check_rooms
*/

#include "generator.h"

void verif_x(Maze *maze, int i)
{
	if (i - 2 < 0)
		maze->room->x_m = 0;
	else
		maze->room->x_m = -2;
	if (i + 2 >= maze->size_x)
		maze->room->x_p = 0;
	else
		maze->room->x_p = 2;
}

void verif_y(Maze *maze, int i)
{
	if (i - 2 < 0)
		maze->room->y_m = 0;
	else
		maze->room->y_m = -2;
	if (i + 2 >= maze->size_y)
		maze->room->y_p = 0;
	else
		maze->room->y_p = 2;
}

void check_rooms(Maze *maz)
{
	verif_x(maz, maz->x);
	if (maz->room->x_m != 0)
		which_av_room(maz, 0, maz->room->x_m);
	if (maz->room->x_p != 0)
		which_av_room(maz, 0, maz->room->x_p);
	verif_y(maz, maz->y);
	if (maz->room->y_m != 0)
		which_av_room(maz, maz->room->y_m, 0);
	if (maz->room->y_p != 0)
		which_av_room(maz, maz->room->y_p, 0);
}

void which_av_room(Maze *maze, int y, int x)
{
	if (check_available_room(maze, y, x) != 0) {
		maze->av_room[0] += 1;
		if (y > 0)
			maze->av_room[3] = 1;
		if (y < 0)
			maze->av_room[4] = -1;
		if (x > 0)
			maze->av_room[1] = 1;
		if (x < 0)
			maze->av_room[2] = -1;
	}
}

int check_available_room(Maze *maze, int room_y, int room_x)
{
	if (maze->map[maze->y + room_y][maze->x + room_x] == ' ' )
		return (1);
	else
		return (0);
}