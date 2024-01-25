
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
void swap (int *a, int *b)
{
	int tmp;
	tmp = *b;
	*b = *a;
	*a = tmp;
}


void quick_sort(int *array, size_t size)
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

int main(void)
{
	clock_t start, end;
	double cpu_time_used;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86,5,9,87,78,546654,2,21,56,56,56,689,4,979,6, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	start = clock();
	quick_sort(array, n);
	end = clock();
	cpu_time_used = ((double) (end- start)) / CLOCKS_PER_SEC;
	printf("exc time %f\n", cpu_time_used);
	printf("\n");
	print_array(array, n);
	return (0);
}
