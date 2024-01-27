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


int quick_sort_t(int *array, int _start, int _end)
{
  
    
  size_t pivot, i, j;
  pivot = array[_end];
  j = 0;
  if (_start != 0)
      i = _start-1;
  else
  i = 0;
  for (i; i < _end-1; i++)
    {
      if (array[i] <= pivot)
        {
          _swap(&array[i], &array[j]);
          j++;
          }
        }
          _swap(&array[i+1], &array[j]);
    return j;
}
void quick_sort_f(int *array, int _start, int _end)
{
    if (_start <= _end)
      {
        int pivot = quick_sort_t(array,_start,_end);
        quick_sort_f (array, 0, pivot-1);
        quick_sort_f(array, pivot +1, _end);}
}


void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quick_sort_f(array,0, size-1);


}
