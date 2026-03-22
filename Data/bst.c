#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

static BSTNode* create_node(char data) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    if (!node) {
        fprintf(stderr, "Error: memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void bst_insert(BSTNode** root, char data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }
    if (data < (*root)->data)
        bst_insert(&(*root)->left, data);
    else if (data > (*root)->data)
        bst_insert(&(*root)->right, data);
    /* duplicate: ignore */
}

BSTNode* bst_search(BSTNode* root, char data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return bst_search(root->left, data);
    return bst_search(root->right, data);
}

int bst_count_nodes(BSTNode* root) {
    if (root == NULL) return 0;
    return 1 + bst_count_nodes(root->left) + bst_count_nodes(root->right);
}

int bst_height(BSTNode* root) {
    if (root == NULL) return 0;
    int left_h = bst_height(root->left);
    int right_h = bst_height(root->right);
    return 1 + (left_h > right_h ? left_h : right_h);
}

void bst_inorder_print(BSTNode* root) {
    if (root == NULL) return;
    bst_inorder_print(root->left);
    printf("%c ", root->data);
    bst_inorder_print(root->right);
}

void bst_free(BSTNode* root) {
    if (root == NULL) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}
