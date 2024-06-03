#include <stdio.h>

// Binary tree node structure
typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

// Pre-order traversal function
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int)) {
    if (tree && func) {
        func(tree->value); // Process the current node
        binary_tree_preorder(tree->left, func); // Traverse left subtree
        binary_tree_preorder(tree->right, func); // Traverse right subtree
    }
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

    // Perform pre-order traversal
    binary_tree_preorder(&node1, print_node_value);
    return 0;
}
