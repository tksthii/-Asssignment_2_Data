#ifndef BST_H
#define BST_H

typedef struct BSTNode {
    char            data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

void     bst_insert(BSTNode** root, char data);
BSTNode* bst_search(BSTNode* root, char data);
int      bst_count_nodes(BSTNode* root);
int      bst_height(BSTNode* root);
void     bst_inorder_print(BSTNode* root);
void     bst_free(BSTNode* root);

#endif

