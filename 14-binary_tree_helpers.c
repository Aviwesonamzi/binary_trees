#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

// Function to create a new binary tree node
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = malloc(sizeof(binary_tree_t));
    if (node == NULL)
        return NULL;

    node->n = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to insert a node as the left-child of another node
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    if (parent == NULL)
        return NULL;

    binary_tree_t *node = binary_tree_node(parent, value);
    if (node == NULL)
        return NULL;

    if (parent->left != NULL)
    {
        node->left = parent->left;
        parent->left->parent = node;
    }
    parent->left = node;

    return node;
}

// Function to insert a node as the right-child of another node
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
    if (parent == NULL)
        return NULL;

    binary_tree_t *node = binary_tree_node(parent, value);
    if (node == NULL)
        return NULL;

    if (parent->right != NULL)
    {
        node->right = parent->right;
        parent->right->parent = node;
    }
    parent->right = node;

    return node;
}

// Function to print the binary tree (simple version)
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    printf("%d\n", tree->n);
    binary_tree_print(tree->left);
    binary_tree_print(tree->right);
}
