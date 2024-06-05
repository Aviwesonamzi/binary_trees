#include "binary_trees.h"

// Function to count the leaves in a binary tree
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    // Base case: if the tree is NULL, return 0
    if (tree == NULL)
        return 0;

    // Check if the current node is a leaf
    if (tree->left == NULL && tree->right == NULL)
        return 1;

    // Recursively count the leaves in the left and right subtrees
    return binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);
}
