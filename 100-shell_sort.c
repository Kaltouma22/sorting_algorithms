#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the Shell sort algorithm with the Knuth sequence.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || !size)
		return;

	/* Initialize gap using Knuth sequence */
	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			/* Shift elements with gap to their correct position */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		/* Print array after each interval decrease */
		print_array(array, size);

		/* Update gap using Knuth sequence */
		gap = (gap - 1) / 3;
	}
}
