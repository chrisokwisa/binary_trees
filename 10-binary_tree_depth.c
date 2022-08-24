#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: A pointer to the node to measure the depth
 * Desc: If tree is NULL,
 * Return: 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->parent != NULL)
		return (binary_tree_depth(tree->parent) + 1);
	else
		return (0);
}
