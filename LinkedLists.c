#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *next;
} node_t;

void push(node_t **head, int val) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL) {
    printf("Error: no memory\n");
    return;
  }
  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}

void print_list(node_t *head) {
  node_t *current = head;
  printf("HEAD -> ");
  while (current != NULL) {
    printf("[%d] -> ", current->val);
    current = current->next;
  }
  printf("NULL\n");
}

void free_list(node_t **head) {
  node_t *current = *head;
  node_t *next;

  printf("\n---FREE_LIST---\n");
  while (current != NULL) {
    next = current->next;
    printf("freeing memory in the node=%d (addr: %p\n)", current->val,
           (void *)current);
    free(current);
    current = next;
  }
  *head = NULL;
  printf("*head = NULL ✓\n");
  printf("---free_list concluded ---\n");
}

int main() {
  node_t *list = NULL;

  push(&list, 10);
  push(&list, 20);
  push(&list, 30);

  printf("List before free\n");
  print_list(list);

  free_list(&list);

  printf("\nList before free\n");
  printf("head is %s\n", list == NULL ? "NULL ✓" : "NOT NULL x");
  return 0;
}
