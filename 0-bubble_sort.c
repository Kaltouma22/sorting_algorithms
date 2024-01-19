#include "sort.h"

/**
 * bubble_sort - Sorts an array of int in ascending order using Bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] = array[j] ^ array[j + 1];
				array[j + 1] = array[j] ^ array[j + 1];
				array[j] = array[j] ^ array[j + 1];

				print_array(array, size);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}
