#include "binary_trees.h"
/**
 * binary_tree_rotate_left - left-rotates a binary tree
 * @tree: root node of the tree to rotate pointer
 *
 * Return: pointer to the new root node after rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pvt, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	pvt = tree->right;
	temp = pvt->left;
	pvt->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pvt;
	pvt->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pvt;
		else
			temp->right = pvt;
	}
	return (pvt);
}
