#include "binary_trees.h"


int recursive_full(const binary_tree_t *tree);


/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: root node of the tree to check pointer
 *
 * Return:	0 when "tree" is NULL not full
 *		1 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_full(tree));
}
/**
 * recursive_full - checks if a binary tree is full recursively
 * @tree: root node of the tree to check pointer
 *
 * Return:	0 when "tree" is not full
 *		1, otherwise
 */
int recursive_full(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    recursive_full(tree->left) == 0 ||
		    recursive_full(tree->right) == 0)
			return (0);
	}
	return (1);
}
