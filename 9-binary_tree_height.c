#include "binary_trees.h"

// Helper function to find the maximum between two numbers
size_t max(size_t a, size_t b) {
    return (a > b) ? a : b;
}

// Recursive function to calculate the height of the binary tree
size_t binary_tree_height(const binary_tree_t *tree) {
    if (tree == NULL) {
        // If the tree is NULL, return 0
        return 0;
    }

    // Calculate the height of the left and right subtrees
    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    // Return the larger of the two heights plus 1 for the current node
    return max(left_height, right_height) + 1;
}
