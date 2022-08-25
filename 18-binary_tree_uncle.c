#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds th uncle of a node
 * @node: pointer to the node to find the uncle
 * Desc: Function must return a pointer to the uncle node
 * Return: If node is NULL, return NULL
 *	ifnode has no uncle, return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
	node->parent == NULL ||
	node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	return (node->parent->parent->left);
}
