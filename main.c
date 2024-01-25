
#include <stdlib.h>
#include <stdio.h>
#include <time.h>



typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}

void swap_node (listint_t *a, listint_t *b)
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


listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}



void insertion_sort_list(listint_t **list)
{
	/*define varaibles*/
	listint_t *current;
	listint_t *head;

	head = *list;
	current = head->next;
	/*check for error handling*/
	if (!(head) || !(head->next))
		return;
	/*loop through the array*/
	while (current)
	{
		/*loop to search for the most lower value*/
		while (current->next && current->n > current->next->n )
		{
			swap_node(current, current->next);
			print_list(head);
		}
		
		current = current->next;
		

	}
}

int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
