#include "binary_trees.h"
#include <stdio.h>

// Binary tree node structure
typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// In-order traversal function
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int)) {
    if (tree == NULL || func == NULL) {
        return; // Do nothing if tree or func is NULL
    }

    binary_tree_inorder(tree->left, func); // Traverse left subtree
    func(tree->value); // Process the current node
    binary_tree_inorder(tree->right, func); // Traverse right subtree
}

// Function to call for each node during traversal
void print_node_value(int value) {
    printf("%d ", value);
}

// Example usage
int main() {
    // Construct a simple binary tree
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    binary_tree_t node5 = {5, NULL, NULL};
    binary_tree_t node4 = {4, NULL, NULL};
    binary_tree_t node3 = {3, NULL, NULL};
    binary_tree_t node2 = {2, &node4, &node5};
    binary_tree_t node1 = {1, &node2, &node3};

    // Perform in-order traversal
    binary_tree_inorder(&node1, print_node_value);
    return 0;
}
