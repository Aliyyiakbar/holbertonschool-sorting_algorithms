#include "sort.h"

/**
 * quick_sort_recursive - helper function that implements the Quick sort
 *                        algorithm recursively
 * @a: The array of integers to be sorted
 * @l: The left index of the sub-array to be sorted
 * @r: The right index of the sub-array to be sorted
 * @ln: The size of the entire array
 */

void quick_sort_recursive(int *a, int l, int r, size_t ln)
{
	int pivot, i, j, temp;

	if (l >= r)
	{
		return;
	}

	pivot = a[r];
	i = l - 1;

	for (j = l; j < r; ++j)
	{
		if (a[j] < pivot)
		{
			++i;
			if (i != j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				print_array(a, ln);
			}
		}
	}

	if (i + 1 != r && a[i + 1] != a[r])
	{
		temp = a[i + 1];
		a[i + 1] = a[r];
		a[r] = temp;
		print_array(a, ln);
	}

	quick_sort_recursive(a, l, i, ln);
	quick_sort_recursive(a, i + 2, r, ln);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *               using the Quick sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	quick_sort_recursive(array, 0, size - 1, size);
}
