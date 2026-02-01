#include "binary_trees.h"

/**
* _tree_depth - measures the depth of a node in a binary tree
* @tree: pointer to the node to measure
*
* Description: Returns the depth of the node in the tree. The depth
* is defined as the number of edges from the node to the root node.
*
* Return: The depth of the binary tree
*/
size_t _tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *node = tree;

	while (node->parent != NULL)
	{
		node = node->parent;
		depth++;
	}
	return (depth);
}

/**
* binary_tree_is_full - checks if a binary tree is full
* @tree: pointer to the root node of the tree
*
* Return: 1 if the tree is full, 0 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_tree, right_tree;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
	{
		left_tree = binary_tree_is_full(tree->left);
		right_tree = binary_tree_is_full(tree->right);
		if (left_tree && right_tree)
			return (1);
		else
			return (0);
	}
	return (0);
}

/**
* check_all_leaves_depth - checks if all leaves in a binary tree
*                          are at the same depth
* @node: pointer to the root of the subtree
* @depth_ref: reference depth to compare the leaves against
*
* Return: 1 if all leaves are at the same depth, 0 otherwise
*/
int check_all_leaves_depth(const binary_tree_t *node, size_t depth_ref)
{
	int left, right;

	if (node == NULL)
		return (1);

	if (node->left == NULL && node->right == NULL)
		return (_tree_depth(node) == depth_ref);

	left = check_all_leaves_depth(node->left, depth_ref);
	right = check_all_leaves_depth(node->right, depth_ref);

	return (left && right);
}
/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree
*
* Return: 1 if the tree is perfect, 0 otherwise
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	const binary_tree_t *node;
	size_t depth_ref;

	if (tree == NULL)
		return (0);

	if (!binary_tree_is_full(tree))
		return (0);

	node = tree;
	while (node->left != NULL)
		node = node->left;

	depth_ref = _tree_depth(node);

	return (check_all_leaves_depth(tree, depth_ref));
}
