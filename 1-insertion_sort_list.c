#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @node_a: First node to be swapped
 * @node_b: Second node to be swapped
 *
 * Return: void
 */
void swap_nodes(listint_t *node_a, listint_t *node_b)
{
	if (node_a->prev)
		node_a->prev->next = node_b;
	if (node_b->next)
		node_b->next->prev = node_a;
	node_a->next = node_b->next;
	node_b->prev = node_a->prev;
	node_a->prev = node_b;
	node_b->next = node_a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *a, *b;

	if (list != NULL || *list != NULL || (*list)->next != NULL)
		return;
	a = (*list)->next;
	while (a)
	{
		b = a;
		a = a->next;
		while(b && b->prev)
		{
			if (b->prev->n > b->n)
			{
				swap_nodes(b->prev, b);
				if (!b->prev)
					*list = b;
				print_list((const listint_t *)*list);
			}
			else
				b = b->prev;
		}
	}
}
