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

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swapped = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swapped;

				print_array(array, size);
				swapped = 1;
			}
		}
		i++;
	}
}
