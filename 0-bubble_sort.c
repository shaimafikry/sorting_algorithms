#include "sort.h"
/**
 * bubble_sort: sotrs elemnt in quic sort
 * @array: pointer to array
 * @size: size of array
 * Return: no return
*/



void bubble_sort(int *array, size_t size)
{
	/*define varaibles*/
	size_t i, j;

	/*check for error handling*/
	if (!array || size == 1)
		return;
	/*loop through the array*/
	for ( i = 0; i < size; i++)
	{
		/*loop to search for the most lower value*/
		for (j = 0; j < size - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1 ]);
				print_array(array, size);

			}
		}

	}
}
