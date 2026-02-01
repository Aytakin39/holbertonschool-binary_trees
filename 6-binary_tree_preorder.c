#include "binary_trees.h"

/**
* binary_tree_preorder - parcourt un arbre binaire en pré-ordre
* @tree: pointeur vers la racine de l'arbre à parcourir
* @func: pointeur vers la fonction à appeler pour chaque nœud
*
* Description: La fonction traverse l'arbre en pré-ordre et
* appelle la fonction `func` sur la valeur de chaque nœud.
* Si `tree` ou `func` est NULL, rien n'est fait.
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
