#ifndef BST_H
#define BST_H

// Define structure for a BST node
typedef struct Node {
    char data;             // stores character value
    struct Node* left;     // pointer to left child
    struct Node* right;    // pointer to right child
} Node;

// Function declarations

// Insert a character into the BST
void bst_insert(Node** root, char data);

// Search for a character in the BST
int bst_search(Node* root, char target);

// Count total number of nodes in the BST
int bst_count_nodes(Node* root);

// Determine height of the BST
int bst_height(Node* root);

// Print BST in sorted order (inorder traversal)
void bst_inorder_print(Node* root);

// Free all nodes in BST
void bst_free(Node* root);

#endif

