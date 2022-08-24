#include "binary_trees.h"

/**
 * binary_tree_inorder - Function goes through a binary tree
 *	using in-order traversal
 *@tree: Pointer to the root node of the tree to traverse
 *@func: A pointer to a function to call for each node.
 *	the value in the node is passed as a parameter to function
 *Desc: If tree or func is NULL do nothing
 *Return: nothing
 */
void binary_tree_inorder(const binary_tree_t *tree,
		void (*func)(int))
{
	if (tree == NULL || *func == NULL)
		return;

	func(tree->n);

	if (tree->left != NULL)
		binary_tree_inorder(tree->left, func);

	if (tree->right != NULL)
		binary_tree_inorder(tree->right, func);
}
