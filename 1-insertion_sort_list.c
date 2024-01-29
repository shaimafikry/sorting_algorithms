#include "sort.h"

/**
 * swap_node - function to swap values of two nodes in a linked list
 * @a: pointer to the first node
 * @b: pointer to the second node
 * Return: void
 */
void swap_node(listint_t *a, listint_t *b)
{
	/* Swap prev pointers */
	listint_t *tmp = a->prev;
	a->prev = b->prev;
	b->prev = tmp;

	/* Update next pointers if not NULL */
	if (a->prev)
		a->prev->next = a;
	if (b->prev)
		b->prev->next = b;

	/* Swap next pointers */
	tmp = a->next;
	a->next = b->next;
	b->next = tmp;

	/* Update prev pointers if not NULL */
	if (a->next)
		a->next->prev = a;
	if (b->next)
		b->next->prev = b;
}

/**
 * insertion_sort_list - sorts elements in a doubly linked list using insertion sort
 * @list: pointer to the head of the list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *head, *tmp;

	/* Check for edge cases */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	head = *list;
	current = head;

	/* Loop through the list */
	while (current)
	{
		/* Loop to search for the lowest value */
		tmp = current;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			/* Swap nodes if necessary */
			swap_node(tmp->prev, tmp);
			print_list(head);
			tmp = tmp->prev;
		}
		current = current->next;
	}
}
