#include "binary_trees.h"

/**
 * get_size - counts the number of nodes in a binary tree
 * @tree: pointer to the root node
 *
 * Return: number of nodes
 */
size_t get_size(binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + get_size(tree->left) + get_size(tree->right));
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node
 * @index: index of the current node
 * @node_count: number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
int is_complete(binary_tree_t *tree, size_t index, size_t node_count)
{
	if (tree == NULL)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, 2 * index + 1, node_count) &&
		is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * get_parent_for_insert - finds the correct parent for a new node
 * @tree: pointer to the root node
 * @index: index of the next node to insert
 * @node_count: total number of nodes after insertion
 *
 * Return: pointer to the parent node where the new node should be inserted
 */
binary_tree_t *get_parent_for_insert(binary_tree_t *tree, size_t index,
	size_t node_count)
{
	if (index == 1)
		return (tree);

	if (get_parent_for_insert(tree, (index - 1) / 2, node_count)->left == NULL
		|| (2 * ((index - 1) / 2) + 1 == index - 1
		&& get_parent_for_insert(tree, (index - 1) / 2,
			node_count)->right == NULL))
		return (get_parent_for_insert(tree, (index - 1) / 2, node_count));

	if (index % 2 == 1)
		return (get_parent_for_insert(tree->left, index / 2, node_count));
	else
		return (get_parent_for_insert(tree->right, index / 2, node_count));
}

/**
 * swap_values - swaps values between two nodes
 * @a: first node
 * @b: second node
 */
void swap_values(binary_tree_t *a, binary_tree_t *b)
{
	int temp;

	temp = a->n;
	a->n = b->n;
	b->n = temp;
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * @value: the value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *new;
	binary_tree_t *parent;
	size_t node_count;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	node_count = get_size(*root) + 1;
	parent = get_parent_for_insert(*root, node_count / 2, node_count);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new;
	else
		parent->right = new;

	/* Bubble up to maintain max heap property */
	while (new->parent && new->n > new->parent->n)
	{
		swap_values(new, new->parent);
		new = new->parent;
	}

	return (new);
}
