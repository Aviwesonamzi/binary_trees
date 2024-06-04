#include "binary_trees.h"
#include <stddef.h>

// Define the binary tree node structure
typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Function prototype as provided
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

// Recursive function to traverse the binary tree in post-order
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int)) {
    if (tree == NULL || func == NULL) {
        // If the tree or func is NULL, do nothing
        return;
    }

    // Traverse the left subtree
    binary_tree_postorder(tree->left, func);
    // Traverse the right subtree
    binary_tree_postorder(tree->right, func);
    // Call the function on the current node's value
    func(tree->value);
}
