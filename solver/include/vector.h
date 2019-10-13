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
	void *item;
	struct vector_s *next;
} vector_t;

vector_t *vector_init(void);
int vector_total(vector_t *);
void vector_add(vector_t **, void *);
void vector_set(vector_t **, int, void *);
void *vector_get(vector_t **, int);
void *vector_pop(vector_t **);
void vector_delete(vector_t **, int);
void vector_free(vector_t *);
void vector_free2(vector_t *);
void vector_free3(vector_t **);

#endif /* VECTOR_H_ */
