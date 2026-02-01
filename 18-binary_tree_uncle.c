#include "binary_trees.h"

/**
* binary_tree_uncle - Finds the uncle of a node in a binary tree
* @node: Pointer to the node to find the uncle of
*
* Return: Pointer to the uncle node
*         If node is NULL or has no uncle, returns NULL
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grandparent;
	binary_tree_t *uncle;

	if (node == NULL)
		return (NULL);

	parent = node->parent;
	if (parent == NULL)
		return (NULL);

	grandparent = parent->parent;
	if (grandparent == NULL)
		return (NULL);

	if (grandparent->left == parent)
		uncle = grandparent->right;
	else
		uncle = grandparent->left;

	return (uncle);
}
