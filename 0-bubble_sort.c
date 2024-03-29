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
 * bubble_sort - sotrs elemnt in quic sort
 * @array: pointer to array
 * @size: size of array
 * Return: no return
*/



void bubble_sort(int *array, size_t size)
{
	/*define varaibles*/
	size_t i, j;

	/*check for error handling*/
	if (array == NULL || size < 2)
		return;
	/*loop through the array*/
	for (i = 0; i < size - 1; i++)
	{
		/*loop to search for the most lower value*/
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				_swap(&array[j], &array[j + 1]);
				print_array(array, size);

			}
		}

	}
}
