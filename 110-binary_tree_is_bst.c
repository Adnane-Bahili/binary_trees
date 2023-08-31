#include "binary_trees.h"
#include "limits.h"


int helper(const binary_tree_t *tree, int low, int high);


/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: root node of the tree to check pointer
 *
 * Return:	1 when the tree is a valid BST
 *		0, otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (helper(tree, INT_MIN, INT_MAX));
}
/**
 * helper - checks if a binary tree is a valid binary search tree
 * @tree: root node of the tree to check pointer
 * @low: value of the smallest node visited thus far
 * @high: value of the largest node visited thus far
 *
 * Return:	1 when the tree is a valid BST
 *		0, otherwise
 */
int helper(const binary_tree_t *tree, int low, int high)
{
	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		return (helper(tree->left, low, tree->n - 1) &&
				helper(tree->right, tree->n + 1, high));
	}
	return (1);
}
