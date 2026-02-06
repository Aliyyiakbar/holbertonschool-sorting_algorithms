#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Gets the maximum value in an integer array
 * @a: Array of integers
 * @n: Size of the array
 * Return: Maximum value found in the array
 */
int get_max(int *a, size_t n)
{
	size_t i;
	int m;

	m = a[0];
	for (i = 1; i < n; i++)
	{
		if (a[i] > m)
		{
			m = a[i];
		}
	}
	return (m);
}

/**
 * mk_count - Builds the counting array (prefix sums) for counting sort
 * @a: Array of integers
 * @n: Size of the array
 * @m: Maximum value in @a
 * Return: Pointer to counting array on success, NULL on failure
 */
int *mk_count(int *a, size_t n, int m)
{
	size_t i;
	int *c;

	c = malloc(sizeof(int) * (m + 1));
	if (!c)
	{
		return (NULL);
	}

	for (i = 0; i < (size_t)(m + 1); i++)
	{
		c[i] = 0;
	}

	for (i = 0; i < n; i++)
	{
		c[a[i]] += 1;
	}

	for (i = 1; i < (size_t)(m + 1); i++)
	{
		c[i] += c[i - 1];
	}

	print_array(c, (size_t)(m + 1));
	return (c);
}

/**
 * fill_out - Fills the output array using the counting array
 * @a: Input array
 * @n: Size of the array
 * @c: Counting array (prefix sums)
 * @o: Output array
 */
void fill_out(int *a, size_t n, int *c, int *o)
{
	size_t i;

	for (i = n; i > 0; i--)
	{
		o[c[a[i - 1]] - 1] = a[i - 1];
		c[a[i - 1]] -= 1;
	}
}

/**
 * copy_back - Copies the output array back into the input array
 * @a: Input array to overwrite with sorted values
 * @n: Size of the array
 * @o: Output array containing sorted values
 */
void copy_back(int *a, size_t n, int *o)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		a[i] = o[i];
	}
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max, *c, *out;

	if (!array || size < 2)
	{
		return;
	}

	max = get_max(array, size);

	out = malloc(sizeof(int) * size);
	if (!out)
	{
		return;
	}

	c = mk_count(array, size, max);
	if (!c)
	{
		free(out);
		return;
	}

	fill_out(array, size, c, out);
	copy_back(array, size, out);

	free(c);
	free(out);
}
