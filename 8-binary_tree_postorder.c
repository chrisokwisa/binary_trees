#include "binary_trees.h"

/**
 * binary_tree_postorder - Function goes through a binary
 *	tree through a post-order traversal
 *@tree: Pointer to the root node of the tree to traverse
 *@func: Pointer to the function to call for each node.
 *	The value in the node must be must be passed as a parameter to function
 *desc: If tree of func is NULL, do nothing
 *Return: Nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	(void)(tree);

	if (tree == NULL || *func == NULL)
		return;

	if (tree->left != NULL)
		binary_tree_postorder(tree->left, func);

	if (tree->right != NULL)
		binary_tree_postorder(tree->right, func);

	func(tree->n);
}

