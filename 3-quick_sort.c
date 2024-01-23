#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 *
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t i = low;
	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			/* swap array[i] and array[j] */
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;

				/* Print array after each swap */
				print_array(array, size);
			}
			i++;
		}
	}
	/* Swap array[i] and array[high] (pivot) */
	if (i != high)
	{
		int temp = array[i];

		array[i] = array[high];
		array[high] = temp;
		/* Print array after pivot placement */
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_recursive - Recursive function for Quick sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
	if (low < high)
	{
		size_t pivot = lomuto_partition(array, low, high, size);

		/* Recursively sort elements before and after the pivot */
		if (pivot > 0)
			quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm with Lomuto partition scheme.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
