#pragma once

typedef struct Node {
    int val;
    struct Node* first_child;
    struct Node* next_sibling;
} Node;

Node* create_node(int);
void add_child(Node*, int);
void preorder(Node*);
void postorder(Node*);
void free_tree(Node*);