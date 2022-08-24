#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance
 * Return: If tree is NULL, Return 0, else return balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
	
}

/**
 * binary_tree_height - Measures the height of a bonary tree
 * @tree: A pointer to the root of the root to measure the height
 *
 * Return: If tree is NULL, your function must return 0 otherwise height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int rightheight, leftheight;

	if (tree == NULL)
		return (0);

	rightheight = binary_tree_height(tree->right);
	leftheight = binary_tree_height(tree->left);
	return (((rightheight >= leftheight) ? rightheight: leftheight) + 1);
}
