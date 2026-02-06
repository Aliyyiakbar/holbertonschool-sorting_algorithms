#include "sort.h"

/**
 * merge - Merges two sorted subarrays into one sorted range
 * @a: Array of integers
 * @b: Buffer array
 * @l: Left index (inclusive)
 * @m: Middle index (start of right, exclusive for left)
 * @r: Right index (exclusive)
 */
void merge(int *a, int *b, size_t l, size_t m, size_t r)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(a + l, m - l);
	printf("[right]: ");
	print_array(a + m, r - m);
	i = l, j = m, k = l;
	while (i < m && j < r)
	{
		if (a[i] <= a[j])
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
		}
		k++;
	}
	while (i < m)
	{
		b[k] = a[i];
		i++;
		k++;
	}
	while (j < r)
	{
		b[k] = a[j];
		j++;
		k++;
	}
	for (i = l; i < r; i++)
	{
		a[i] = b[i];
	}
	printf("[Done]: ");
	print_array(a + l, r - l);
}

/**
 * msort - Recursively applies top-down merge sort on a range
 * @a: Array of integers
 * @b: Buffer array
 * @l: Left index (inclusive)
 * @r: Right index (exclusive)
 */
void msort(int *a, int *b, size_t l, size_t r)
{
	size_t m;

	if (r - l < 2)
	{
		return;
	}

	m = l + (r - l) / 2;

	msort(a, b, l, m);
	msort(a, b, m, r);
	merge(a, b, l, m, r);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *b;

	if (!array || size < 2)
	{
		return;
	}

	b = malloc(sizeof(int) * size);
	if (!b)
	{
		return;
	}

	msort(array, b, 0, size);

	free(b);
}
