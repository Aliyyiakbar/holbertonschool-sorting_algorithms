#include "sort.h"

/**
 * _swap - Swaps two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void _swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * sift_down - Restores the max-heap property in a subtree
 * @a: Array of integers
 * @n: Heap size
 * @i: Root index of the subtree to sift down
 * @sz: Full array size (for printing)
 */
void sift_down(int *a, size_t n, size_t i, size_t sz)
{
	size_t l, r, m;

	while (1)
	{
		l = i * 2 + 1, r = i * 2 + 2, m = i;

		if (l < n && a[l] > a[m])
		{
			m = l;
		}
		if (r < n && a[r] > a[m])
		{
			m = r;
		}
		if (m == i)
		{
			break;
		}

		_swap(&a[i], &a[m]);
		print_array(a, sz);
		i = m;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm (sift-down)
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i, n;

	if (!array || size < 2)
	{
		return;
	}

	n = size;

	for (i = (n / 2); i > 0; --i)
	{
		sift_down(array, n, i - 1, size);
	}

	for (i = n - 1; i > 0; --i)
	{
		_swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}
