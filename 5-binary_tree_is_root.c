#include "binary_trees.h"
/**
 * binary_tree_is_root - checks if a node is a root of a binary tree
 * @node: node to check pointer
 *
 * Return: 1 when the node is a root
 *         0 otherwise, or when the node is NULL
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
