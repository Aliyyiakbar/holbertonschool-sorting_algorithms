#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int max;
	int *c, *out;

	if (!array || size < 2)
	{
		return;
	}

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	c = malloc(sizeof(int) * (max + 1));
	if (!c)
	{
		return;
	}

	out = malloc(sizeof(int) * size);
	if (!out)
	{
		free(c);
		return;
	}

	for (i = 0; i < (size_t)(max + 1); i++)
	{
		c[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		c[array[i]] += 1;
	}

	for (i = 1; i < (size_t)(max + 1); i++)
	{
		c[i] += c[i - 1];
	}

	print_array(c, (size_t)(max + 1));

	for (i = size; i > 0; i--)
	{
		out[c[array[i - 1]] - 1] = array[i - 1];
		c[array[i - 1]] -= 1;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = out[i];
	}

	free(out);
	free(c);
}
