#include "binary_trees.h"
/**
 * bst_insert - inserts a value in the Binary Search Tree
 * @tree: root node of the BST to insert the value in pointer
 * @value: value to store in the node to be inserted
 *
 * Return: created node pointer
 *		NULL when it fails
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *crnt, *new;

	if (tree != NULL)
	{
		crnt = *tree;

		if (crnt == NULL)
		{
			new = binary_tree_node(crnt, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}
		if (value < crnt->n)
		{
			if (crnt->left != NULL)
				return (bst_insert(&crnt->left, value));
			new = binary_tree_node(crnt, value);
			if (new == NULL)
				return (NULL);
			return (crnt->left = new);
		}
		if (value > crnt->n)
		{
			if (crnt->right != NULL)
				return (bst_insert(&crnt->right, value));
			new = binary_tree_node(crnt, value);
			if (new == NULL)
				return (NULL);
			return (crnt->right = new);
		}
	}
	return (NULL);
}
