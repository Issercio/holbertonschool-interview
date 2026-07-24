#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted subarrays
 * @array: Original array
 * @buffer: Temporary buffer
 * @left: Left index
 * @mid: Middle index
 * @right: Right index
 */
static void merge(int *array, int *buffer,
	size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
		buffer[k++] = (array[i] <= array[j]) ? array[i++] : array[j++];

	while (i < mid)
		buffer[k++] = array[i++];

	while (j < right)
		buffer[k++] = array[j++];

	for (k = left; k < right; k++)
		array[k] = buffer[k];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively sorts array
 * @array: Array to sort
 * @buffer: Temporary buffer
 * @left: Left index
 * @right: Right index
 */
static void merge_sort_recursive(int *array, int *buffer,
	size_t left, size_t right)
{
	size_t mid;

	if (right - left < 2)
		return;

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, buffer, left, mid);
	merge_sort_recursive(array, buffer, mid, right);

	merge(array, buffer, left, mid, right);
}

/**
 * merge_sort - Sorts an array using Merge Sort
 * @array: Array to sort
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}
