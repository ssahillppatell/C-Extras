#include "binarysearch.h"
#include <stdlib.h>
#include <stdio.h>

Node* create_node(int val) {
    Node* node = malloc(sizeof(Node));
    node->value = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert_node(Node* root, int val) {
    if(root->value > val) {
        if(root->left) insert_node(root->left, val);
        else root->left = create_node(val);
    } else if(root->value < val) {
        if(root->right) insert_node(root->right, val);
        else root->right = create_node(val);
    }
}

Node* search_node(Node* root, int val) {
    if(root == NULL || root->value == val) {
        return root;
    }

    if(root->value < val) return search_node(root->right, val);
    return search_node(root->left, val);
}

void delete_node(Node* root, int val) {
    Node* parent = NULL;
    Node* current = root;

    while(current != NULL && current->value != val) {
        parent = current;
        if(current->value < val) current = current->right;
        else current = current->left;
    }

    if(current == NULL) return;

    if(current->left == NULL && current->right == NULL) {
        if(current != root) {
            if(parent->left == current) parent->left = NULL;
            else parent->right = NULL;
        } else free(root);
    } else if(current->left != NULL && current->right != NULL) {
        Node* successor = current->right;
        while(successor->left) successor = successor -> left;
        int temp = successor->value;
        delete_node(root, successor->value);
        current->value = temp;
    } else {
        Node* child = current->left ? current->left : current->right;
        if(current != root) {
            if(parent->left == current) parent->left = child;
            else parent->right = child;
            free(current);
        } else free(root);
    }
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right); 
}

void preorder(Node* root) {
    if(root == NULL) return;
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right); 
}

void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right); 
    printf("%d ", root->value);
}

void free_tree(Node* root) {
    if(root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}