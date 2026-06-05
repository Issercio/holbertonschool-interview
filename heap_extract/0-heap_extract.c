#include "binary_trees.h"
#include <stdlib.h>

/* Helper prototypes */
static size_t tree_size(const heap_t *tree);
static heap_t *get_last_node(heap_t *root, size_t size);
static void heapify_down(heap_t *root);

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: double pointer to the root node of the heap
 *
 * Return: value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last;
	int value;
	size_t size;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	/* If tree has only one node */
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	size = tree_size(*root);

	/* Find last level-order node */
	last = get_last_node(*root, size);

	/* Replace root value with last node value */
	(*root)->n = last->n;

	/* Remove last node */
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);

	/* Restore heap property */
	heapify_down(*root);

	return (value);
}

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to the tree
 *
 * Return: number of nodes
 */
static size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * get_last_node - gets the last level-order node
 * @root: pointer to the root node
 * @size: size of the heap
 *
 * Return: pointer to the last node
 */
static heap_t *get_last_node(heap_t *root, size_t size)
{
	size_t mask;
	heap_t *node = root;

	mask = 1;

	while (mask <= size)
		mask <<= 1;

	mask >>= 2;

	while (mask > 0)
	{
		if (size & mask)
			node = node->right;
		else
			node = node->left;

		mask >>= 1;
	}

	return (node);
}

/**
 * heapify_down - restores max heap property
 * @root: pointer to the root node
 */
static void heapify_down(heap_t *root)
{
	heap_t *largest;
	int temp;

	while (root)
	{
		largest = root;

		if (root->left && root->left->n > largest->n)
			largest = root->left;

		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest == root)
			break;

		temp = root->n;
		root->n = largest->n;
		largest->n = temp;

		root = largest;
	}
}
