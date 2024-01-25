#include "sort.h"
/**
 * insertion_sort_list: sotrs elemnt in insertion_sort_list
 * @list: pointer to array
 * Return: no return
*/



void insertion_sort_list(listint_t **list)
{
	/*define varaibles*/
	listint_t *current;
	listint_t *head;

	head = *list;
	current = *list;
	/*check for error handling*/
	if (!*list || !head->next)
		return;
	/*loop through the array*/
	while (current)
	{
		/*loop to search for the most lower value*/
		while (current && current->n > current->next->n )
		{
			swap_node(current, current->next);
			print_list(head);
			current = current->prev;
		}
		current = current->next;
		

	}
}
