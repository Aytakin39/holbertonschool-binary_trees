#include <stdlib.h>
#include "binary_trees.h"

/**
* binary_tree_node - Creates a binary tree node
* @parent: Pointer to the parent node of the new node
* @value: Value to store in the new node
*
* Description: Allocates memory for a new binary tree node,
* initializes its value to `value`, sets its parent to `parent`,
* and its left and right children to NULL.
*
* Return: Pointer to the newly created node, or NULL on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}
