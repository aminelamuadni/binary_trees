#include "binary_trees.h"

/**
 * depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node of the tree to measure the depth
 *
 * Return: Depth of the tree
 */
size_t depth(const binary_tree_t *tree)
{
	size_t d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect_recursive - Helper function to check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @d: Depth of the tree
 * @level: Current level in the tree
 *
 * Return: 1 if tree is perfect, 0 if not
 */
int is_perfect_recursive(const binary_tree_t *tree, size_t d, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect_recursive(tree->left, d, level + 1) &&
		   is_perfect_recursive(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 if not or if tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t d = depth(tree);

	return (is_perfect_recursive(tree, d, 0));
}
