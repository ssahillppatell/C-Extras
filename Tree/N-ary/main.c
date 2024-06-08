#include "n-ary.h"
#include <stdio.h>

int main() {
    Node* root = create_node(1);
    add_child(root, 2);
    add_child(root, 3);
    add_child(root, 4);
    add_child(root->first_child, 6);
    add_child(root->first_child->next_sibling, 5);
    add_child(root->first_child->next_sibling->next_sibling, 10);
    add_child(root->first_child->next_sibling->next_sibling, 11);
    add_child(root->first_child, 7);
    add_child(root->first_child->first_child->next_sibling, 8);
    add_child(root->first_child->first_child->next_sibling, 9);

    printf("Preorder: "); preorder(root); printf("\n");
    printf("Postorder: "); postorder(root); printf("\n");

    free_tree(root);

    return 0;
}