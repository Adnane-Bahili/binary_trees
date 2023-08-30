#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 * @parent: parent of the node to create pointer
 * @value: value to put in new node
 *
 * Return:	new node pointer
 *		NULL when an error occurs
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
