#include "sort.h"

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

/**
 * insertion_sort_list - sotrs elemnt in insertion_sort_list
 * @list: pointer to array
 * Return: no return
*/



void insertion_sort_list(listint_t **list)
{
	/*define varaibles*/
	listint_t *current;
	listint_t *head;
	listint_t *tmp;

	head = *list;
	current = *list;
	/*check for error handling*/
	if (!*list || !head->next)
		return;
	/*loop through the array*/
	while (current)
	{
		/*loop to search for the most lower value*/
		tmp = current;
		while (tmp->next && tmp->n > tmp->next->n)
		{
			swap_node(current, current->next);
			print_list(head);
			tmp = tmp->prev->prev;
		}
		current = current->next;
	}
}
