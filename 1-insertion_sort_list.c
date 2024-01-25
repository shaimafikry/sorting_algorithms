#include "sort.h"
/**
 * quick_sort: sotrs elemnt in quic sort
 * @array: pointer to array
 * @size: size of array
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
	if (!*list)
		return;
	/*loop through the array*/
	while (current->next)
	{
		/*loop to search for the most lower value*/
		while (current->next != NULL && current->n > current->next->n )
		{
			swap_node(current, current->next);
			print_list(head);
		}
		current = current->next;
		

	}
}
