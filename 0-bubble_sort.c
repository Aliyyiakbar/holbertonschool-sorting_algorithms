#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 *               order using the Bubble sort algorithm
 *
 * @array: input array
 * @size: input size
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, i;

	for (x = 0; x < size; ++x)
	{
		for (i = 0; i < size - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
			}
		}
		print_array(array, size);
	}
}
