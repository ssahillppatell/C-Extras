#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

Node* create_node(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(!node) exit(EXIT_FAILURE);
    
    node->data = data;
    return node;
}

Node* append_node(Node** ll, int data) {
    Node* node = create_node(data);
    Node* current = (*ll);

    while(current -> next) {
        current = current->next;
    }
    current->next = node;

    return node;
}

Node* prepend_node(Node**ll, int data) {
    Node* node = create_node(data);
    node->next = (*ll);
    (*ll) = node;

    return node;
}

int pop_node(Node** ll) {
    Node* current = *ll;
    Node* last;
    while(current->next) {
        if(!current->next->next) {
            last = current;
        }
        current = current->next;
    }
    last->next = NULL;
    
    int data = current->data;
    free(current);

    return data;
}

int shift_node(Node** ll) {
    Node* current = *ll;
    *ll = current->next;
    int data = current->data;
    free(current);

    return data;
}

void free_list(Node** ll) {
    Node* current = *ll;
    Node* next;

    while(current) {
        next = current->next;
        printf("Freeing %d\n", current->data);
        free(current);
        current = next;
    }
    *ll = NULL;
}

void print_list(Node** ll) {
    Node* current = *ll;
    while(current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}