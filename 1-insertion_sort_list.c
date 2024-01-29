#include "sort.h"

/**
 * swap_node - function to swap values of two nodes in a linked list
 * @a: pointer to the first node
 * @b: pointer to the second node
 * @list: pointer to the fisr node
 * Return: void
 */
void swap_node(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *tmp;

	if (a == b)
		return;

	tmp = a->prev;
	a->next = b->next;
	a->prev = b;
	if (a->next != NULL)
		a->next->prev = a;
	b->next = a;
	b->prev = tmp;
	if (b->prev == NULL)
		*list = b;
	else
		b->prev->next = b;

	}

/**
 * insertion_sort_list - sorts elements in a db list insertion sort
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
tmp = current->prev;
while (tmp && tmp->n > tmp->next->n)
{
	/* Swap nodes if necessary */
	swap_node(&head, tmp, tmp->next);
	print_list(head);
	tmp = tmp->prev->prev;
}

current = current->next;
if (current == NULL)
	*list = head;
}
}
