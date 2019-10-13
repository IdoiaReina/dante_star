/*
** EPITECH PROJECT, 2018
** particle.c
** File description:
** particle engine function
*/

#include "vector.h"

vector_t *vector_init(void)
{
	vector_t *v = malloc(sizeof(*v));

	if (v == NULL)
		return (NULL);
	v->next = NULL;
	return (v);
}

int vector_total(vector_t *v)
{
	int total = 0;
	vector_t *tmp = v->next;

	while (tmp) {
		total += 1;
		tmp = tmp->next;
	}
	return (total);
}

void vector_free(vector_t *v)
{
	vector_t *tmp = v->next;
	vector_t *tmp2;

	while (tmp) {
		tmp2 = tmp->next;
		free(tmp->item);
		free(tmp);
		tmp = tmp2;
	}
	free(v);
}

void vector_free2(vector_t *v)
{
	vector_t *tmp = v->next;
	vector_t *tmp2;

	while (tmp) {
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

void vector_free3(vector_t **v)
{
	vector_t *tmp;

	while ((*v)->next) {
		tmp = (*v)->next;
		free(*v);
		*v = tmp;
	}
}