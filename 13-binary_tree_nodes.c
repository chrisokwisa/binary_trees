#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with atleast 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * DEsc: If tree is NULL, the function must return 0
 * Return: size of the nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	size += 1;
	size += binary_tree_nodes(tree->left);
	size += binary_tree_nodes(tree->right);
	return (size);
}
