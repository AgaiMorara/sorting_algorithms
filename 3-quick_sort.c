#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @array: the array
 * @a: index of the first integer
 * @b: index of the second integer
 */
void swap(int *array, int a, int b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: the array
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(array, i + 1, high);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - recursive function to perform Quick sort
 * @array: the array
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using Quick sort
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);

}
