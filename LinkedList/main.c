#include "linkedlist.h"
#include <stdio.h>

int main() {
  Node* ll = create_node(4);
  printf(":help\n");
  append_node(&ll, 3);
  append_node(&ll, 2);
  append_node(&ll, 21);
  prepend_node(&ll, 1);
  prepend_node(&ll, 122);

  print_list(&ll);

  printf("%d\n", pop_node(&ll));
  printf("%d\n", shift_node(&ll));

  print_list(&ll);

  free_list(&ll);
  

  return 0;
}
