#include <stdlib.h>

typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL) {
	// Return NULL if memory allocation fails    
        return NULL;
    }

    new_node->value = value;
    new_node->parent = parent;
    // When created, a node does not have any children
    new_node->left = NULL;
    // When created, a node does not have any children
    new_node->right = NULL;

    return new_node;
}
