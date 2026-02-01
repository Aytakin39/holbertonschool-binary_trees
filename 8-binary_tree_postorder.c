#include "binary_trees.h"

/**
 * binary_tree_postorder - traverses a binary tree in post-order
 * @tree: pointer to the root node of the tree
 * @func: function to call on each node's value
 *
 * Description: Visits nodes in post-order (left → right → node)
 * and applies func to each node. Does nothing if tree or func is NULL.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
