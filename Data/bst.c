#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

/*
 * Function: bst_insert
 * --------------------
 * Inserts a character into the BST.
 * If the character already exists, it is ignored.
 *
 * root: pointer to root pointer (allows modification)
 * data: character to insert
 */
void bst_insert(Node** root, char data) {
    // If tree is empty, create new node
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }

    // Insert into left subtree
    if (data < (*root)->data) {
        bst_insert(&(*root)->left, data);
    }
    // Insert into right subtree
    else if (data > (*root)->data) {
        bst_insert(&(*root)->right, data);
    }
    // Duplicate values are ignored
}

/*
 * Function: bst_search
 * --------------------
 * Searches for a target character in the BST.
 *
 * Returns 1 if found, 0 otherwise.
 */
int bst_search(Node* root, char target) {
    if (root == NULL) return 0;

    if (target == root->data) return 1;
    else if (target < root->data)
        return bst_search(root->left, target);
    else
        return bst_search(root->right, target);
}

/*
 * Function: bst_count_nodes
 * -------------------------
 * Counts total number of nodes in the BST.
 */
int bst_count_nodes(Node* root) {
    if (root == NULL) return 0;

    return 1 + bst_count_nodes(root->left) + bst_count_nodes(root->right);
}

/*
 * Function: bst_height
 * --------------------
 * Computes height of the BST.
 *
 * Height is defined as number of nodes
 * along the longest path from root to leaf.
 */
int bst_height(Node* root) {
    if (root == NULL) return 0;

    int leftHeight = bst_height(root->left);
    int rightHeight = bst_height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

/*
 * Function: bst_inorder_print
 * ---------------------------
 * Prints the BST in sorted order using inorder traversal.
 */
void bst_inorder_print(Node* root) {
    if (root == NULL) return;

    bst_inorder_print(root->left);
    printf("%c ", root->data);
    bst_inorder_print(root->right);
}

/*
 * Function: bst_free
 * ------------------
 * Frees all memory allocated for the BST.
 */
void bst_free(Node* root) {
    if (root == NULL) return;

    bst_free(root->left);
    bst_free(root->right);
    free(root);
}