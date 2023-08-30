#include "binary_trees.h"
/**
 * binary_tree_preorder - goes through binary tree using an pre-order traversal
 * Description: when "tree" or "func" is NULL, does nothing
 * @tree: root node of the tree to traverse pointer
 * @func: function to call for each node pointer
 *
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
