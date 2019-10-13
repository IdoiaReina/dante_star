/*
** EPITECH PROJECT, 2018
** vector.h
** File description:
** header files
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct vector_s {
	int item;
	struct vector_s *next;
} vector_t;

vector_t *vector_init(void);
void vector_add(vector_t **, int);
int vector_pop_end(vector_t **v);

#endif /* VECTOR_H_ */
