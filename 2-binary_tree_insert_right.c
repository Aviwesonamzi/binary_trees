#include <stdlib.h>

typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value) {
    if (parent == NULL) {
        return NULL;
    }

    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL) {
        return NULL;
    }

    new_node->value = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = parent->right;
    if (new_node->right != NULL) {
        new_node->right->parent = new_node;
    }
    parent->right = new_node;

    return new_node;
}
