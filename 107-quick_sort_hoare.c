#include "sort.h"

/**
 * qh_sw - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void qh_sw(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * qh_pt - Partitions an array using Hoare scheme (pivot is last element value)
 * @a: Array of integers
 * @lo: Low index (inclusive)
 * @hi: High index (inclusive)
 * @sz: Full array size (for printing)
 * Return: Partition index
 */
ssize_t qh_pt(int *a, ssize_t lo, ssize_t hi, size_t sz)
{
	int p;
	ssize_t i, j;

	p = a[hi], i = lo - 1, j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (a[i] < p);

		do {
			j--;
		} while (a[j] > p);

		if (i >= j)
		{
			return (j);
		}

		qh_sw(&a[i], &a[j]);
		print_array(a, sz);
	}
}

/**
 * qh_sc - Recursively sorts an array using Quick sort (Hoare partition)
 * @a: Array of integers
 * @lo: Low index (inclusive)
 * @hi: High index (inclusive)
 * @sz: Full array size (for printing)
 */
void qh_sc(int *a, ssize_t lo, ssize_t hi, size_t sz)
{
	ssize_t p;

	if (lo < hi)
	{
		p = qh_pt(a, lo, hi, sz);

		if (p == hi)
		{
			p--;
		}

		qh_sc(a, lo, p, sz);
		qh_sc(a, p + 1, hi, sz);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm (Hoare partition)
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	qh_sc(array, 0, (ssize_t)size - 1, size);
}
