#include "binary_trees.h"


levelorder_queue_t *node_creation(binary_tree_t *node);
void queue_freed(levelorder_queue_t *head);
void push_pint(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));


/**
 * binary_tree_levelorder - traverses a binary tree using level-order traversal
 * @tree: node of the tree to traverse pointer
 * @func: function to call for each node pointer
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;
	head = tail = node_creation((binary_tree_t *)tree);
	if (head == NULL)
		return;
	while (head != NULL)
	{
		push_pint(head->node, head, &tail, func);
		pop(&head);
	}
}
/**
 * node_creation - creates a new levelorder_queue_t node
 * @node: binary tree node for the new node to contain
 *
 * Return:	pointer to the new node
 *		NULL when an error occurs
 */
levelorder_queue_t *node_creation(binary_tree_t *node)
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
 * queue_freed - frees a levelorder_queue_t queue
 * @head: head of the queue pointer
 *
 * Return: void
 */
void queue_freed(levelorder_queue_t *head)
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
 * push_pint -	runs a function on a given binary tree node and
 *			pushes the children into a levelorder_queue_t queue
 * Description: exits with a status code of 1 when "malloc" fails
 * @node: binary tree node to print and push
 * @head: head of the queue double pointer
 * @tail: tail of the queue double pointer
 * @func: pointer to the function to call on @node
 *
 * Return: void
 */
void push_pint(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *new;

	func(node->n);
	if (node->left != NULL)
	{
		new = node_creation(node->left);
		if (new == NULL)
		{
			queue_freed(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (node->right != NULL)
	{
		new = node_creation(node->right);
		if (new == NULL)
		{
			queue_freed(head);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}
/**
 * pop - pops head of a levelorder_queue_t queue
 * @head: head of the queue double pointer
 *
 * Return: void
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
