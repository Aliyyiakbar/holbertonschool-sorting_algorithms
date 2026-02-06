#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *              using the Shell sort algorithm (Knuth sequence)
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (!array || size < 2)
	{
		return;
	}

	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap >= 1)
	{
		for (i = gap; i < size; ++i)
		{
			tmp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
