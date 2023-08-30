#include "binary_trees.h"
/**
 * binary_tree_inorder - goes through a binary tree using an in-order traversal
 * Description: when "tree" or "func" is NULL, do nothing
 * @tree: root node of the tree to traverse pointer
 * @func: function to call for each node pointer
 *
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
