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
 * quick_sort_t - function to get pivot
 * @array: pointer to the first value
 * @_start: array start
 * @_end: array end
 * Return:pivot
*/

int quick_sort_t(int *array, size_t size, int _start, int _end)
{
	int pivot, i, j;
	pivot = array[_end];
	for (i = j = _start; i < _end; i++)
	{
		if (array[i] < pivot)
		{
			if (i < j)
			{
				_swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
			j++;
		
	}
	if (array[i] > pivot)
	{
		_swap(&array[j], &array[_end]);
		print_array(array, size);
	}
	return j;
}

/**
 * quick_sort_f - function to get pivot
 * @array: pointer to the first value
 * @_end: array end
 * Return:pivot
*/
void quick_sort_f(int *array, size_t size,  int _start, int _end)
{
	int pivot;

	if (_end - _start > 0)
	{
		pivot = quick_sort_t(array, size, _start, _end);
		quick_sort_f(array, size, _start, pivot - 1);
		quick_sort_f(array, size, pivot + 1, _end);
	}
}
/**
 * quick_sort - function to get pivot
 * @array: pointer to the first value
 * @size: array size
 * Return: pivot
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_f(array, size, 0, size - 1);
}
