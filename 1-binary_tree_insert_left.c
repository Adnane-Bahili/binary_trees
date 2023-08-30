#include "binary_trees.h"
/**
 * binary_tree_insert_left -	inserts a node
 *				as a left-child of of another in a binary tree
 * Description:	when a parent has a left-child already, the new node
 *		takes that place and the old left-child is treated as
 *		the left-child of the new node
 * @parent: node to insert the left-child in pointer
 * @value: value to store in new node
 *
 * Return:	new node pointer
 *		NULL when an error occurs
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
		parent->left->parent = new;
	}
	parent->left = new;
	return (new);
}
