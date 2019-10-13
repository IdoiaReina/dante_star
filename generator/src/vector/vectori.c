/*
** EPITECH PROJECT, 2018
** particle.c
** File description:
** particle engine function
*/

#include "vector.h"

vector_t *vector_init(void)
{
	vector_t *v = NULL;

	return (v);
}

void vector_add(vector_t **v, int item)
{
	vector_t *new = NULL;

	new = malloc(sizeof(*new));
	if (!(new))
		return;
	new->item = item;
	new->next = *v;
	*v = new;
}

int vector_pop_end(vector_t **v)
{
	vector_t *tmp;
	int ret;

	tmp = (*v)->next;
	ret = (*v)->item;
	free (*v);
	*v = tmp;
	return (ret);
}