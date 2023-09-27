#include "sort.h"
/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: a pointer to a pointer to the head of the list
 * @a: the first node to swap
 * @b: the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t temp;

	if (a == b || *list == NULL)
		return;
	if (a->prev != NULL)
		a->prev->next = b;
	if (b->prev != NULL)
		b->prev->next = a;

	if (a->next != NULL)
		a->next->prev = b;
	if (b->next != NULL)
		b->next->prev = a;
	if (a->prev == NULL)
		*list = b;
	else if (b->prev == NULL)
		*list = a;

	temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;

	temp = a->next;
	a->next = b->next;
	b->next = temp;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending ..
 * @list: a pointer to a pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ahead, behind;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ahead = (*list)->next;

	while (ahead != NULL)
	{
		behind = ahead->prev;
		while (behind != NULL && behind->n > ahead->n)
		{
			swap_nodes(list, behind, ahead);
			print_list(*list);
			behind = ahead->prev;
		}
		ahead = ahead->next;
    }
}
