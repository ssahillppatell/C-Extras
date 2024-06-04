typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int);

Node* append_node(Node**, int);
Node* prepend_node(Node**, int);
int pop_node(Node**);
int shift_node(Node**);
void free_list(Node**);
void print_list(Node**);