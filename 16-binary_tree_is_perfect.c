#include "binary_trees.h"


unsigned char leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *leaf_get(const binary_tree_t *tree);
int recursive_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);


/**
 * leaf - checks if a node is a leaf of a binary tree
 * @node: pointer to the node to check
 *
 * Return:	1 when the node is a leaf
 *		0 otherwise
 */
unsigned char leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}
/**
 * depth - returns the depth of a given node in a binary tree
 * @tree: pointer to the node to measure the depth of
 *
 * Return: node depth
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}
/**
 * leaf_get - returns a leaf of a binary tree
 * @tree: pointer to the root node of the tree to find a leaf in
 *
 * Return: first encountered leaf pointer
 */
const binary_tree_t *leaf_get(const binary_tree_t *tree)
{
	if (leaf(tree) == 1)
		return (tree);
	return (tree->left ? leaf_get(tree->left) : leaf_get(tree->right));
}
/**
 * recursive_perfect - checks if a binary tree is perfect recursively
 * @tree: A pointer to the root node of the tree to check
 * @leaf_depth: The depth of one leaf in the binary tree
 * @level: current node level
 *
 * Return: 1 when the tree is perfect
 *		0, otherwise
 */
int recursive_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (recursive_perfect(tree->left, leaf_depth, level + 1) &&
		recursive_perfect(tree->right, leaf_depth, level + 1));
}
/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: root node of the tree to check pointer
 *
 * Return: 0 when "tree" is NULL or not perfect
 *         1, otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursive_perfect(tree, depth(leaf_get(tree)), 0));
}
