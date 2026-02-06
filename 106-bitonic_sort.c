#include "sort.h"

/**
 * bt_sw - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void bt_sw(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * bt_mg - Merges a bitonic sequence in a given direction
 * @a: Array of integers
 * @lo: Start index
 * @ct: Count of elements in the sequence
 * @dr: Direction (1 for UP, 0 for DOWN)
 */
void bt_mg(int *a, size_t lo, size_t ct, int dr)
{
	size_t i, k;

	if (ct < 2)
	{
		return;
	}

	k = ct / 2;
	for (i = lo; i < lo + k; i++)
	{
		if ((dr && a[i] > a[i + k]) || (!dr && a[i] < a[i + k]))
		{
			bt_sw(&a[i], &a[i + k]);
		}
	}

	bt_mg(a, lo, k, dr);
	bt_mg(a, lo + k, k, dr);
}

/**
 * bt_sq - Recursively builds and sorts bitonic sequences (top-down)
 * @a: Array of integers
 * @lo: Start index
 * @ct: Count of elements in the sequence
 * @dr: Direction (1 for UP, 0 for DOWN)
 * @sz: Full array size (for printing)
 */
void bt_sq(int *a, size_t lo, size_t ct, int dr, size_t sz)
{
	size_t k;
	char *s;

	if (ct < 2)
	{
		return;
	}

	s = (dr) ? "UP" : "DOWN";
	printf("Merging [%lu/%lu] (%s):\n", (unsigned long)ct, (unsigned long)sz, s);
	print_array(a + lo, ct);

	k = ct / 2;
	bt_sq(a, lo, k, 1, sz);
	bt_sq(a, lo + k, k, 0, sz);
	bt_mg(a, lo, ct, dr);

	printf("Result [%lu/%lu] (%s):\n", (unsigned long)ct, (unsigned long)sz, s);
	print_array(a + lo, ct);
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm
 * @array: Array to sort
 * @size: Size of the array (assumed to be 2^k)
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}

	bt_sq(array, 0, size, 1, size);
}
