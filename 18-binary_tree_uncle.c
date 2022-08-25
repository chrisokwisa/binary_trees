#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds th uncle of a node
 * @node: pointer to the node find the uncle
 * Desc: Function must return a pointer to the uncle node
 * Return: If node is NULL, return NULL
 *	ifnode has no uncle, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle;

	if (node == NULL || node->parent->parent
	|| node->parent->parent->left
	|| node->parent->parent->right)
		return (0);

	uncle = node->parent->parent->right;
	uncle = (node->parent == uncle) ? node->parent->parent->left : uncle;

	return (uncle);
}
