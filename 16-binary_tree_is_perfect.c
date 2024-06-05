#include "binary_trees.h"

/**
 * binary_tree_is_perfect_recursive - Check if a binary tree is perfect recursively
 * @tree: Pointer to the root node of the tree
 * @depth: Depth of the leftmost node
 * @level: Current level in the recursion
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect_recursive(const binary_tree_t *tree, size_t depth, size_t level)
{
    if (tree == NULL)
        return 1;

    // Check if it is a leaf node
    if (tree->left == NULL && tree->right == NULL)
        return (depth == level + 1);

    // If an internal node and it doesn't have both children
    if (tree->left == NULL || tree->right == NULL)
        return 0;

    // Check recursively for both subtrees
    return binary_tree_is_perfect_recursive(tree->left, depth, level + 1) &&
           binary_tree_is_perfect_recursive(tree->right, depth, level + 1);
}

/**
 * binary_tree_depth - Calculate the depth of the leftmost node
 * @tree: Pointer to the root node of the tree
 *
 * Return: Depth of the leftmost node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;
    while (tree)
    {
        depth++;
        tree = tree->left;
    }
    return depth;
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t depth = binary_tree_depth(tree);
    return binary_tree_is_perfect_recursive(tree, depth, 0);
}
