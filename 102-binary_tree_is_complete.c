#include "binary_trees.h"


levelorder_queue_t *node_creation(binary_tree_t *node);
void queue_freed(levelorder_queue_t *head);
void node_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void head_pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);


/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * Description: exits with a status code of 1 when "malloc" fails
 * @tree: root node of the tree to traverse pointer
 *
 * Return:	0 when the tree is NULL or not complete
 *		1, otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flg = 0;

	if (tree == NULL)
		return (0);
	head = tail = node_creation((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);
	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flg == 1)
			{
				queue_freed(head);
				return (0);
			}
			node_push(head->node->left, head, &tail);
		}
		else
			flg = 1;
		if (head->node->right != NULL)
		{
			if (flg == 1)
			{
				queue_freed(head);
				return (0);
			}
			node_push(head->node->right, head, &tail);
		}
		else
			flg = 1;
		head_pop(&head);
	}
	return (1);
}
/**
 * node_creation - creates a new levelorder_queue_t node
 * @node: binary tree node for the new node to contain
 *
 * Return:	new node pointer
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
 * node_push - pushes a node to the back of a levelorder_queue_t queue
 * Description: exits with a status code of 1 when "malloc" fails
 * @node: binary tree node to print and push
 * @head: head of the queue double pointer
 * @tail: tail of the queue double pointer
 *
 *
 * Return: void
 */
void node_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = node_creation(node);
	if (new == NULL)
	{
		queue_freed(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}
/**
 * head_pop - pops the head of a levelorder_queue_t queue
 * @head: head of the queue double pointer
 */
void head_pop(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
