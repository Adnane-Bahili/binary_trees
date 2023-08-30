#include "binary_trees.h"
/**
 * binary_tree_is_leaf - checks if a node is a leaf of a binary tree
 * @node: node to check pointer
 *
 * Return: 1 when the node is a leaf
 *         0 otherwise, or when the node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);
	return (1);
}
