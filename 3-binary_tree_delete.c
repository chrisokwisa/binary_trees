#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer tothe root node of the tree to delete
 * Desc: If tree is NULL, do nothing
 * Return: nothing since it is a void function
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
	{
		binary_tree_delete(tree->left);
	}
	if (tree->right != NULL)
	{
		binary_tree_delete(tree->right);
	}
	free(tree);
}
