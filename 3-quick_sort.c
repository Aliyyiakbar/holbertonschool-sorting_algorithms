#include "sort.h"

void quick_sort_recursive(int *a, int l, int r, size_t ln)
{
	if (l < r)
	{
		int pivot = a[r], i = l - 1, j, temp;

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
		if (i + 1 != r)
		{
			temp = a[i + 1];
			a[i + 1] = a[r];
			a[r] = temp;

			print_array(a, ln);
		}

		quick_sort_recursive(a, l, i, ln);
		quick_sort_recursive(a, i + 2, r, ln);
	}
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
