#include "binarysearch.h"
#include <stdio.h>

int main() {
    Node* root = create_node(8);
    insert_node(root, 3);
    insert_node(root, 6);
    insert_node(root, 4);
    insert_node(root, 5);
    insert_node(root, 10);
    delete_node(root, 11);
    delete_node(root, 4);

    printf("Preorder: "); preorder(root); printf("\n");
    printf("Inorder: "); inorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    printf("Searching for 1: %s\n", search_node(root, 1) ? "Found": "Not Found");
    printf("Searching for 4: %s\n", search_node(root, 4) ? "Found": "Not Found");

    return 0;
}