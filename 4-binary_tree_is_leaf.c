#include <stdlib.h>

typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

int binary_tree_is_leaf(const binary_tree_t *node) {
    // Check if the node is NULL
    if (node == NULL) {
        return 0;
    }
    // Check if both left and right children are NULL
    if (node->left == NULL && node->right == NULL) {
        return 1; // It's a leaf node
    }
    return 0; // It's not a leaf node
}	
