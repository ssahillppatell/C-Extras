#include "n-ary.h"
#include <stdlib.h>
#include <stdio.h>

Node* create_node(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->first_child = NULL;
    node->next_sibling = NULL;

    return node;
}

void add_child(Node* subtree, int val) {
    Node* new_node = create_node(val);

    Node* current = subtree->first_child;
    if(current == NULL) {
        subtree->first_child = new_node;
        return;
    }
    while(current->next_sibling) {
        current = current->next_sibling;
    }

    current->next_sibling = new_node;
}

void preorder(Node* tree) {
    printf("%d ", tree->val);
    if(tree->first_child) preorder(tree->first_child);
    if(tree->next_sibling) preorder(tree->next_sibling);
}

void postorder(Node* tree) {
    if(tree->first_child) postorder(tree->first_child);
    printf("%d ", tree->val);
    if(tree->next_sibling) postorder(tree->next_sibling);
}

void free_tree(Node* tree) {
    if(tree->first_child) free(tree->first_child);
    if(tree->next_sibling) free(tree->next_sibling);
    free(tree);
}