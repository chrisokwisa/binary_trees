#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node  - creates a new levelorder_queue_t node
 * @node: The binary tree node for the new node to contain
 *
 * Return: If an error occurs, NULL
 *	othrewise, a pointer to the new node
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue
 * @head: A pointer to the head of the queue
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *		pushes its children int a levelorder_queue_t queue
 *@node: The binary tree node to print and push
 *@head: A double pointer to the haed to the head of the queue
 *@tail: A double pointer to the tail of the queue
 *@func: pointer to the function to call on @node
 * Desc: Upon malloc failure, exists with a status code of 1
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = create_node(node->left);
		if (new == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = create_node(node->right);
		if (new == NULL);
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - pops the head of a levelorder_queue_t queue
 * @head: A double pointer to the head of the queue
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
 * binary_tree_levelorder - Function that goes througha binary
 *	tree using level-order traversal
 *@tree: pointer to the root node of the tree to traverse
 *@func: pointer to the function to call for each node.
 *	The value in the node must be passed as a parameter to this function
 *Return: If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void
		(*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
