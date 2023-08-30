#include "binary_trees.h"


size_t binary_tree_height(const binary_tree_t *tree);


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: root node of the tree to measure the balance factor pointer
 *
 * Return:	balance factor
 *		when "tree" is NULL, must return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	return (0);
}
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: root node of the tree to measure the height pointer
 *
 * Return:	height
 *		when "tree" is NULL, must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lft, rght;

	if (tree == NULL)
		return (0);
	lft = binary_tree_height(tree->left);
	rght = binary_tree_height(tree->right);
	if (lft >= rght)
		return (1 + lft);
	return (1 + rght);
}
