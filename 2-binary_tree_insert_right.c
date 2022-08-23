#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: A pointer to the node to insert the right-chid in
 * @value: The value to store in the new node
 * Desc: If parent already has a right-child, the new node
 *	must take its place, and the old right-child must
 *	be set as the right-child of the new node
 *Return: A pointer to the create node,
 *	or NULL on failure of prent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = parent;
	}
	parent->right = new;

	return (new);
}
