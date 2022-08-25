#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Desc: Function must return a o=pointer to the lowest common ancestor node
 *	of the two given nodes
 *Return: If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	for (first_depth = depth(first); first_depth > 1; first_depth--)
		first = first->parent;
	for (second_depth = depth(second); second_depth > 1; second_depth--)
		second = second->parent;

	if (first == second)
		return ((binary_tree_t *)first->parent);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}

/**
 * depth - measure the deoth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 *
 * Return: If tree is NULL, your function must return 0, else return the depth
 */
size_t depth(const binary_tree_t *tree)
{
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);

}
