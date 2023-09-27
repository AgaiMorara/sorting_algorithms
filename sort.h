#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


/**
 *swap: swaps postions of two types
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

void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

#endif
