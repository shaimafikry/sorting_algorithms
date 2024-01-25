#include "sort.h"
/**
 * quick_sort: sotrs elemnt in quic sort
 * @array: pointer to array
 * @size: size of array
 * Return: no return
*/



void selection_sort(int *array, size_t size);
{
	/*define varaibles*/
	size_t i, min, j;

	/*check for error handling*/
	if (!array || size == 1)
		return;
	/*loop through the array*/
	for ( i = 0; i < size; i++)
	{
		/*assign the first value to min*/
		min = i;
		/*loop to search for the most lower value*/
		for (j = i; j < size; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}

		
		if (min != i)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
		
	}
}
