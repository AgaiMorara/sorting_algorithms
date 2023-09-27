#include "sort.h"

/**
 *bubble_sort - sorts an array in numeric or lexographic order
 *@array: array to be sorted
 *@size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
