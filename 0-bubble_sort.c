#include "sort.h"

/**
 *swap - swaps postions of two types
 *@array: the list to swap
 *@pos1: first position
 *@pos2: second position
 *
 */

void swap(int *array, int pos1, int pos2)
{
	int temp = array[pos1];

	array[pos1] = array[pos2];
	array[pos2] = temp;
}

/**
 *bubble_sort - sorts an array in numeric or lexographic order
 *@array: array to be sorted
 *@size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag;

	if (size <= 0 || array == NULL)
		return;

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
