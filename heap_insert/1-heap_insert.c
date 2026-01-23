#include "binary_trees.h"

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree (0 if NULL)
 */
int tree_height(binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * is_perfect - checks if a binary tree is perfect at a given height
 * @tree: pointer to the root node of the tree
 * @leaf_height: height of the tree
 * @level: current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect(binary_tree_t *tree, int leaf_height, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (leaf_height == level);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, leaf_height, level + 1) &&
		is_perfect(tree->right, leaf_height, level + 1));
}

/**
 * get_last_node - finds the last node in a complete binary tree
 * @tree: pointer to the root node
 *
 * Return: pointer to the last node
 */
binary_tree_t *get_last_node(binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (NULL);

	height = tree_height(tree);

	if (is_perfect(tree, height, 0))
		return (tree);

	if (is_perfect(tree->left, height - 1, 0))
		return (get_last_node(tree->right));

	return (get_last_node(tree->left));
}

/**
 * get_node_parent - finds the parent of the last node in a complete binary tree
 * @tree: pointer to the root node
 * @height: height of the tree
 *
 * Return: pointer to the parent of the last node
 */
binary_tree_t *get_node_parent(binary_tree_t *tree, int height)
{
	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL || tree->right == NULL)
		return (tree);

	if (is_perfect(tree->left, height - 1, 0))
		return (get_node_parent(tree->right, height - 1));

	return (get_node_parent(tree->left, height - 1));
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
	int height;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	height = tree_height(*root);
	parent = get_node_parent(*root, height);

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
		int temp = new->n;
		new->n = new->parent->n;
		new->parent->n = temp;
		new = new->parent;
	}

	return (new);
}
