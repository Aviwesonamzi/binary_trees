#include <stdlib.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: A pointer to the root node of the tree to delete
 *
 * Description: If tree is NULL, do nothing. Uses post-order traversal.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        // Recursively delete left subtree
        binary_tree_delete(tree->left);
        // Recursively delete right subtree
        binary_tree_delete(tree->right);
        // Delete current node
        free(tree);
    }
}
