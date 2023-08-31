#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int helper(const binary_tree_t *tree, int low, int high);
int binary_tree_is_avl(const binary_tree_t *tree);


/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return:	1 when the tree is a valid AVL tree
 *		0, otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (helper(tree, INT_MIN, INT_MAX));
}
/**
 * height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height
 *		when the tree is NULL, function must return 0
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left = 0, right = 0;

		left = tree->left ? 1 + height(tree->left) : 1;
		right = tree->right ? 1 + height(tree->right) : 1;
		return ((left > right) ? left : right);
	}
	return (0);
}
/**
 * helper - checks if a binary tree is a valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * @low: value of the smallest node visited thus far
 * @high: value of the largest node visited thus far
 *
 * Return:  1 when the tree is a valid AVL tree
 *		0, otherwise
 */
int helper(const binary_tree_t *tree, int low, int high)
{
	size_t left_height, right_height, difference;

	if (tree != NULL)
	{
		if (tree->n < low || tree->n > high)
			return (0);
		left_height = height(tree->left);
		right_height = height(tree->right);
		difference = left_height > right_height ?
			left_height - right_height : right_height - left_height;
		if (difference > 1)
			return (0);
		return (helper(tree->left, low, tree->n - 1) &&
				helper(tree->right, tree->n + 1, high));
	}
	return (1);
}
