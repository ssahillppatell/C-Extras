#pragma once

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int);
void insert_node(Node*, int);
Node* search_node(Node*, int);
void delete_node(Node*, int);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
void free_tree(Node*);