#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

int main() {
    Node* root = NULL;

    // Seed random number generator
    srand(time(NULL));

    // Generate random number between 11 and 20
    int n = rand() % 10 + 11;

    printf("Number of characters to insert: %d\n", n);
    printf("Inserted characters: ");

    // Insert random lowercase characters into BST
    for (int i = 0; i < n; i++) {
        char c = 'a' + rand() % 26;
        printf("%c ", c);
        bst_insert(&root, c);
    }

    printf("\n");

    // Print characters in sorted order
    printf("Sorted characters (inorder traversal): ");
    bst_inorder_print(root);
    printf("\n");

    // Count nodes
    int totalNodes = bst_count_nodes(root);
    printf("Number of nodes in BST: %d\n", totalNodes);

    // Get height of tree
    int height = bst_height(root);
    printf("Height of BST: %d\n", height);

    // Free allocated memory
    bst_free(root);

    return 0;
}