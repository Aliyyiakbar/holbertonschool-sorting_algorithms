#include "sort.h"

/**
 * rs_mx - Gets the maximum value in an integer array
 * @a: Array of integers
 * @n: Size of the array
 * Return: Maximum value found in the array
 */
int rs_mx(int *a, size_t n)
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
 * rs_cd - Performs a stable counting sort by a single digit (LSD pass)
 * @a: Array of integers
 * @n: Size of the array
 * @e: Current exponent (1, 10, 100, ...)
 * @o: Output buffer array
 */
void rs_cd(int *a, size_t n, int e, int *o)
{
	size_t i;
	int c[10];

	for (i = 0; i < 10; ++i)
	{
		c[i] = 0;
	}

	for (i = 0; i < n; ++i)
	{
		c[(a[i] / e) % 10] += 1;
	}

	for (i = 1; i < 10; ++i)
	{
		c[i] += c[i - 1];
	}

	for (i = n; i > 0; --i)
	{
		o[c[(a[i - 1] / e) % 10] - 1] = a[i - 1];
		c[(a[i - 1] / e) % 10] -= 1;
	}

	for (i = 0; i < n; ++i)
	{
		a[i] = o[i];
	}
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the LSD Radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int m, e;
	int *o;

	if (!array || size < 2)
	{
		return;
	}

	m = rs_mx(array, size);

	o = malloc(sizeof(int) * size);
	if (!o)
	{
		return;
	}

	for (e = 1; m / e > 0; e *= 10)
	{
		rs_cd(array, size, e, o);
		print_array(array, size);
	}

	free(o);
}
