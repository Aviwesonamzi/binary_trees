#include "binary_trees.h"
#include <stdlib.h>

typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *parent; // Assuming your binary_tree_t structure has a parent pointer
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

int binary_tree_is_root(const binary_tree_t *node) {
    // Check if the node is NULL
    if (node == NULL) {
        return 0;
    }
    // Check if the node's parent is NULL
    if (node->parent == NULL) {
        return 1; // It's a root node
    }
    return 0; // It's not a root node
}
