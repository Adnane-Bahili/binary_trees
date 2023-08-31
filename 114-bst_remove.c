#include "binary_trees.h"


bst_t *successor_inorder(bst_t *root);
bst_t *delete_bst(bst_t *root, bst_t *node);
bst_t *recursive_remove(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);


/**
 * bst_remove - removes a node from a binary search tree
 * Description: when the node to be deleted has two children, it
 *		is replaced with its first in-order successor
 * @root: pointer to the root node of the BST to remove a node from
 * @value: value to remove in the BST
 *
 * Return: pointer to the new root node after deletion
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (recursive_remove(root, root, value));
}
/**
 * successor_inorder - returns the minimum value of a binary search tree
 * @root: pointer to the root node of the BST to search
 *
 * Return: minimum value in @tree
 */
bst_t *successor_inorder(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
/**
 * delete_bst - deletes a node from a binary search tree
 * @root: pointer to the root node of the BST
 * @node: pointer to the node to delete from the BST
 *
 * Return: pointer to the new root node after deletion
 */
bst_t *delete_bst(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}
	successor = successor_inorder(node->right);
	node->n = successor->n;
	return (delete_bst(root, successor));
}
/**
 * recursive_remove - removes a node from a binary search tree recursively
 * @root: pointer to the root node of the BST to remove a node from
 * @node: pointer to the current node in the BST
 * @value: value to remove from the BST
 *
 * Return: pointer to the root node after deletion
 */
bst_t *recursive_remove(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (delete_bst(root, node));
		if (node->n > value)
			return (recursive_remove(root, node->left, value));
		return (recursive_remove(root, node->right, value));
	}
	return (NULL);
}
