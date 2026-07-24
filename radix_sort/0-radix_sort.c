#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Gets the largest value in an array
 * @array: Array of integers
 * @size: Number of elements
 *
 * Return: Maximum value
 */
static int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sorts array according to significant digit
 * @array: Array of integers
 * @size: Number of elements
 * @exp: Current exponent (1, 10, 100...)
 */
static void counting_sort(int *array, size_t size, int exp)
{
	int count[10] = {0};
	int *output;
	int i;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array using LSD Radix Sort algorithm
 * @array: Array of integers
 * @size: Number of elements
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}
