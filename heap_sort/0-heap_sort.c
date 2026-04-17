#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Maintains the max-heap property for a subtree
 * @array: The array to heapify
 * @size: Total size of the array
 * @root: Index of the root of the subtree
 * @end: Index of the last element in the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left <= end && array[left] > array[largest])
		largest = left;
	if (right <= end && array[right] > array[largest])
		largest = right;
	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		sift_down(array, size, largest, end);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array || size < 2)
		return;

	/* Build max heap */
	for (i = (size - 2) / 2 + 1; i > 0; i--)
		sift_down(array, size, i - 1, size - 1);

	/* Heap sort */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
