#include "sort.h"
/**
 * _swap - function to swap values
 * @a: pointer to the first value
 * @b: pointer to the second value
 * Return: no return
*/
void _swap(int *a, int *b)
{
	int tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}


/**
 * swap_node - function to swap values
 * @a: pointer to the first value
 * @b: pointer to the second value
 * Return: no return
*/
void swap_node(listint_t *a, listint_t *b)
{
	listint_t *tmp;

	tmp = a;
	a->next = b->next;
	if (b->next != NULL)
		b->next->prev = a;
	a->prev = b;

	b->next = tmp;
	b->prev = tmp->prev;
	if (tmp->prev != NULL)
		b->prev->next = b;
}
