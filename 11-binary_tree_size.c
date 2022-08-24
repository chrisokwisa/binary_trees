#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: Pointer to the root node of the root of the tree to measure the size
 * Desc: If tree is NULL, the function must return 0
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);
	return (size + 1);
}
