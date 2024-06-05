#include "binary_trees.h"

// Function to check if a binary tree is full
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    // If the node is a leaf node
    if (tree->left == NULL && tree->right == NULL)
        return 1;

    // If both left and right children are present, recursively check them
    if (tree->left != NULL && tree->right != NULL)
        return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);

    // If the node has exactly one child
    return 0;
}
