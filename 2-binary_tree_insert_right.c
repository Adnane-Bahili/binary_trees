#include "binary_trees.h"
/**
 * binary_tree_insert_right -	inserts a node as the right-child
 *				of another in a binary tree
 * Description:	when a parent has a right-child already, the new node
 *		takes that place and the old right-child is treated as
 *		the right-child of the new node
 * @parent: node to insert the right-child in pointer
 * @value: value to store in new node
 *
 * Return:	new node pointer
 *		NULL when an error occurs
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
		parent->right->parent = new;
	}
	parent->right = new;
	return (new);
}
