#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * Description: Creates a new node and inserts it as the left child of
 * the parent node. If the parent already has a left child, the new
 * node replaces it and the old left child becomes the left child of
 * the new node.
 *
 * Return: Pointer to the newly created node, or NULL on failure or if
 * parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	if (parent->left != NULL)
	{
	new_node->left = parent->left;
	parent->left->parent = new_node;
	}
	parent->left = new_node;

	return (new_node);
}
