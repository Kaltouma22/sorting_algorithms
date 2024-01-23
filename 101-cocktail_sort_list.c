#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Cocktail Shaker sort algorithm.
 *
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *crnt;

	if (list == NULL || *list == NULL)
		return;

	for (;;)
	{
		swapped = 0;

		for (crnt = *list; crnt->next != NULL; crnt = crnt->next)
		{
			if (crnt->n > crnt->next->n)
			{
				swap_nodes(list, &crnt, &(crnt->next));
				swapped = 1;
				print_list(*list);
			}
		}
		if (!swapped)
			break;

		swapped = 0;

		for (crnt = crnt->prev; crnt->prev != NULL; crnt = crnt->prev)
		{
			if (crnt->n < crnt->prev->n)
			{
				swap_nodes(list, &(crnt->prev), &crnt);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to the head of the doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */

void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *temp_prev, *temp_next;

	temp_prev = (*a)->prev;
	temp_next = (*b)->next;

	if (temp_prev)
		temp_prev->next = *b;
	else
		*list = *b;
	if (temp_next)
		temp_next->prev = *a;

	(*a)->prev = *b;
	(*a)->next = temp_next;
	(*b)->prev = temp_prev;
	(*b)->next = *a;
}
