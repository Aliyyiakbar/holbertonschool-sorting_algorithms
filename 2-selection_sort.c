#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, mn_idx;
	int tmp;

	if (!array || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		mn_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[mn_idx])
			{
				mn_idx = j;
			}
		}
		if (mn_idx != i)
		{
			tmp = array[i];
			array[i] = array[mn_idx];
			array[mn_idx] = tmp;
			print_array(array, size);
		}
	}
}
