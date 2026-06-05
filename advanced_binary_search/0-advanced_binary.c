#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the current subarray
 * @array: Pointer to the array
 * @left: Left index
 * @right: Right index
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		if (i < right)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}

/**
 * binary_recursive - Recursive binary search helper
 * @array: Pointer to the array
 * @left: Left index
 * @right: Right index
 * @value: Value to search for
 *
 * Return: Index of first occurrence, or -1
 */
int binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		/* Check if it's the first occurrence */
		if (mid == left || array[mid - 1] != value)
			return ((int)mid);

		/* Continue searching on the left side */
		return (binary_recursive(array, left, mid, value));
	}

	if (array[mid] < value)
		return (binary_recursive(array, mid + 1, right, value));

	return (binary_recursive(array, left, mid, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_recursive(array, 0, size - 1, value));
}