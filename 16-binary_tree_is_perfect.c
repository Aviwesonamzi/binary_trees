#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree && tree->parent)
    {
        depth++;
        tree = tree->parent;
    }

    return (depth);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    if (tree->left == NULL && tree->right == NULL)
        return (1);

    return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

/**
 * binary_tree_is_perfect_recursive - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @d: depth of the tree
 * @level: current level in the tree
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect_recursive(const binary_tree_t *tree, int d, int level)
{
    if (tree == NULL)
        return (1);

    if (tree->left == NULL && tree->right == NULL)
        return (d == level + 1);

    if (tree->left == NULL || tree->right == NULL)
        return (0);

    return (binary_tree_is_perfect_recursive(tree->left, d, level + 1) &&
            binary_tree_is_perfect_recursive(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int d = binary_tree_depth(tree);

    if (tree == NULL)
        return (0);

    return (binary_tree_is_perfect_recursive(tree, d, 0));
}
