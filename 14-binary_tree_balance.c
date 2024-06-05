#include "binary_trees.h"

// Function to measure the balance factor of a binary tree
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    int left_height = (int)binary_tree_height(tree->left);
    int right_height = (int)binary_tree_height(tree->right);

    return left_height - right_height;
}
