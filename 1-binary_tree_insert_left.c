#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: A pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 * Desc: If parent has a left-child, the new node must take its place
 *	the old left child must be set as the left-child of thr new node
 *Return: If parent fails - NULL of parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = parent;
	}
	parent->left = new;

	return (new);
}
