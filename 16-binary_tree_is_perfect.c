#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int  sub_tree_perfect(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * binary_tree_height - Checks the height of the binary tree
 * @tree: pointer to the root of the tree to measure the height
 * Return: If tree is NULL, function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int Rightheight, Leftheight;

	if (tree == NULL)
		return (0);

	Rightheight = binary_tree_height(tree->right);
	Leftheight = binary_tree_height(tree->left);
	return (1 + ((Rightheight >= Leftheight) ? Rightheight : Leftheight));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * sub_tree_perfect - finds the size of a subtree
 * @tree: Pointer to the rootnode of the tree to measure the sub-tree
 *Return: 0
 */
int sub_tree_perfect(const binary_tree_t *tree)
{
	if (tree && (tree->right == NULL && tree->left == NULL))
		return (1);

	if (tree && tree->right && tree->left)
		return (1 && sub_tree_perfect(tree->left)
		&& sub_tree_perfect(tree->right));

	return (0);
}

/**
 * binary_tree_is_perfect - checksif a binary tree is perfect
 * @tree: poionter to the root node of the root tree to check
 * Return: If tree is NULL, function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (binary_tree_balance(tree) != 0)
		return (0);

	return (sub_tree_perfect(tree->left) && sub_tree_perfect(tree->right));

}
