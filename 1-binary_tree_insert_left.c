#include <stdlib.h>

typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value) {
    if (parent == NULL) {
	 // Return NULL if parent is NULL
        return NULL;
    }

    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL) {
	 // Return NULL if memory allocation fails
        return NULL;
    }

    new_node->value = value;
    new_node->parent = parent;
    // Set the old left-child as the left-child of the new node
    new_node->left = parent->left;
    new_node->right = NULL;

    if (parent->left != NULL) {
    // Update the parent of the old left-child
        parent->left->parent = new_node;
    }
    // Set the new node as the left-child of the parent
    parent->left = new_node;

     // Return the pointer to the created node
    return new_node; 
}
