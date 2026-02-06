#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *              using the Shell sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; ++i)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
