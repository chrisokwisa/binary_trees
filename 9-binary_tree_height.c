#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *Desc: If tree is NULL,
 *Return: always 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t Leftheight;
	size_t Rightheight;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
	{
		return (0);
	}
	else
	{
		Leftheight = binary_tree_height(tree->left) + 1;
		Rightheight = binary_tree_height(tree->right) + 1;

		if (Leftheight > Rightheight)
			return (Leftheight);

		else
			return (Rightheight);
	}
}
