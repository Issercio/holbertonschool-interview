#include "binary_trees.h"

/**
 * create_avl - Recursively builds AVL tree from sorted array
 * @array: Pointer to first element
 * @start: Start index
 * @end: End index
 * @parent: Pointer to parent node
 * Return: Pointer to root node
 */
avl_t *create_avl(int *array, int start, int end, avl_t *parent)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);
	root->n = array[mid];
	root->parent = parent;
	root->left = create_avl(array, start, mid - 1, root);
	root->right = create_avl(array, mid + 1, end, root);
	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to first element
 * @size: Number of elements
 * Return: Pointer to root node, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (create_avl(array, 0, (int)size - 1, NULL));
}
