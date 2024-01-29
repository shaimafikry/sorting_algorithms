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

	tmp = a->prev;
	a->prev = b->prev;
	b->prev = tmp;

	tmp = a->next;
	a->next = b->next;
	b->next = tmp;
	
	if (a->next != NULL)
		a->next->prev = a;
	if (a->prev != NULL)
		a->prev->next = a;
	if (b->next != NULL)
		b->next->prev = b;
	 if (b->prev != NULL)
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

if (*list == NULL || list == NULL)
		return;

	head = *list;
	current = head;
	/*check for error handling*/
	
	/*loop through the array*/
	while (current)
	{
		/*loop to search for the most lower value*/
		tmp = current;
		while (current->next && current->n > current->next->n)
		{
			swap_node(current, current->next);
			print_list(head);
			current = current->prev->prev;
			if (current == NULL)
				break;
		}
		current = tmp->next;
	}
}
