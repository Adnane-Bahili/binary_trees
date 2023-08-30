#include "binary_trees.h"
/**
 * binary_tree_postorder - traverses a binary tree using a post-order traversal
 * Description: when "tree" or "func" is NULL, do nothing
 * @tree: root node of the tree to traverse pointer
 * @func: function to call for each node pointer
 *
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
