/*
** EPITECH PROJECT, 2018
** particle.c
** File description:
** particle engine function
*/

#include "vector.h"

void vector_add(vector_t **v, void *item)
{
	vector_t *new = NULL;
	vector_t *tmp = *v;

	new = malloc(sizeof(*new));
	if (!(new))
		return;
	new->item = item;
	new->next = NULL;
	if (*v == NULL)
		*v = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void vector_set(vector_t **v, int index, void *item)
{
	vector_t *tmp = (*v)->next;
	int i = 0;

	if (index >= 0 && index < vector_total(*v)) {
		while (i < index) {
			tmp = tmp->next;
			i += 1;
		}
		tmp->item = item;
	}
}

void *vector_get(vector_t **v, int index)
{
	vector_t *tmp = (*v)->next;
	int i = 0;

	if (index >= 0 && index < vector_total(*v)) {
		while (i < index) {
			tmp = tmp->next;
			i += 1;
		}
		return (tmp->item);
	}
	return (NULL);
}

void *vector_pop(vector_t **v)
{
	vector_t *tmp;
	void *ret;

	tmp = (*v)->next;
	ret = (*v)->item;
	*v = tmp;
	return (ret);
}

void vector_delete(vector_t **v, int index)
{
	vector_t *tmp = vector_get(v, index);

	vector_pop(&tmp);
}
