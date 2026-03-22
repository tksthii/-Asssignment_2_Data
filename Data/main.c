#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define MIN_CHARS  11
#define MAX_CHARS  20
#define ALPHA_SIZE 26

int main(void) {
    srand((unsigned int)time(NULL));

    BSTNode* root = NULL;

    int count = MIN_CHARS + rand() % (MAX_CHARS - MIN_CHARS + 1);
    printf("Attempting to insert %d random character(s)...\n\n", count);

    for (int i = 0; i < count; i++) {
        char ch = 'a' + rand() % ALPHA_SIZE;
        printf("  Inserting: '%c'\n", ch);
        bst_insert(&root, ch);
    }

    printf("\n=== Characters in sorted order ===\n");
    bst_inorder_print(root);
    printf("\n");

    printf("\n=== Tree Statistics ===\n");
    printf("Number of nodes : %d\n", bst_count_nodes(root));
    printf("Tree height     : %d\n", bst_height(root));

    bst_free(root);
    root = NULL;

    return 0;
}
