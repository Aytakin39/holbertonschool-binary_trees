#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - traverses a binary tree in-order
 * @tree: pointer to the root node of the tree
 * @func: function to call on each node's value
 *
 * Description: Visits nodes in in-order (left → node → right)
 * and applies func to each node. Does nothing if tree or func is NULL.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
