#include "sort.h"
/**
 * swap - function to swap values
 * @a: pointer to the first value
 * @b: pointer to the second value
 * Return: no return
*/
void swap (int *a, int *b)
{
	int tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}


/**
 * swap - function to swap values
 * @a: pointer to the first value
 * @b: pointer to the second value
 * Return: no return
*/
void swap_node (listint_t *a, listint_t *b)
{
	a->next = b->next;
	a->prev = b;
	if (b->next != NULL)
		b->next->prev = a;
	b->next = a;
	b->prev = a->prev;
	if (a->prev!= NULL)
		a->prev->next = b;

}
