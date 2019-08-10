#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

typedef struct Node Node;

Node* create_node(int val, Node* next) {
  Node* new_node = (Node*)malloc(sizeof(Node));

  if (new_node == NULL) {
    printf("Error creating node");
    exit(0);
  }

  new_node->data = val;
  new_node->next = next;
  return new_node;
}

Node* find(Node* head, int val) {
  Node* cursor = head;

  while(cursor != NULL) {
    if (cursor->data == val) 
      return cursor;

    cursor = cursor->next;
  }

  return cursor;
}

Node* append(Node* head, int val) {
  Node* cursor = head;

  // Go to the last node
  while(cursor->next != NULL)
    cursor = cursor->next;

  Node* new_node = create_node(val, NULL);
  cursor->next = new_node;

  return head;
}

Node* insert_after(Node* head, int after_val, int new_val) {
  Node* after_node = find(head, after_val);
  Node* new_node = create_node(new_val, NULL);

  if (after_node == NULL) {
    return head;
  }

  Node* after_node_next = after_node->next;
  after_node->next = new_node;

  if (after_node_next) {
    new_node->next = after_node_next;
  }

  return head;
}

Node* insert_before(Node* head, int before_val, int new_val) {
  Node* before_node = head;
  Node* after_node = NULL;
  Node* new_node = create_node(new_val, NULL);

  while(before_node != NULL) {
    if (before_node->next->data == before_val) {
      break;
    }

    before_node = before_node->next;
  }

  if (before_node != NULL) {
    after_node = before_node->next;
    before_node->next = new_node;
    new_node->next = after_node;
  }

  return head;
}

Node* reverse(Node* head) {
  Node* prev = NULL;
  Node* current = head;
  Node* next;
  
  while(current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  head = prev;
  return head;
}

int count(Node* head) {
  int c = 0;
  Node* cursor = head;
  while (cursor != NULL)
  {
    c++;
    cursor = cursor->next;
  }

  return c;
}

void print_list(Node* head) {
  Node* cursor = head;

  while (cursor->next != NULL)
  {
    cursor = cursor->next;
    printf("%d \n", cursor->data);
  }
}

int main() {
  Node* head = create_node(1, NULL);

  head = append(head, 2);
  head = append(head, 3);
  head = append(head, 4);
  head = append(head, 5);
  head = insert_after(head, 3, 10);
  head = insert_before(head, 5, 15);
  head = reverse(head);

  print_list(head);
  int total = count(head);
  printf("Total: %d \n", total);
  return 0;
}

