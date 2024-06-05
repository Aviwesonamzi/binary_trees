#include "binary_trees.h"

// Function to count the nodes with at least one child in a binary tree
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    // Base case: if the tree is NULL, return 0
    if (tree == NULL)
        return 0;

    // Check if the current node has at least one child
    if (tree->left != NULL || tree->right != NULL)
        return 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);

    // If the current node has no children, continue with the subtrees
    return binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
}
