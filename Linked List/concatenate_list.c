#include <stdio.h>
#include <stdlib.h>

/*
Roll No: 20CS8016
Q: Write a function to concatenate two lists head_1 and head_2 into one big list head.
*/

typedef struct node {
  int data;
  struct node* next_node;
} node;


node * head_1 = NULL;
node * head_2 = NULL;

node * head = NULL;

void concatenate(node * head_ofA, node * head_ofB) {


  node * ptr; 
  ptr = head_ofA;

  if (ptr == NULL){
    printf("Empty\n");
  } else {
    while (ptr -> next_node != NULL) {
      ptr = ptr -> next_node;
    }
    ptr -> next_node = head_ofB;
  }

  head = head_ofA;
}



void push_into_A(int value) {

  node *newptr = (node*)malloc(sizeof(node));
  newptr -> data = value;

  if (head_1 == NULL){
    newptr -> next_node = NULL;
    head_1 = newptr;

  } else {
    node * temp;
    temp = head_1;

    while (temp -> next_node != NULL){
      temp = temp -> next_node;
    }

    temp -> next_node = newptr;
    newptr -> next_node = NULL;
  }
}
void push_into_B(int value) {

  node *newptr = (node*)malloc(sizeof(node));
  newptr -> data = value;

  if (head_2 == NULL){
    newptr -> next_node = NULL;
    head_2 = newptr;

  } else {
    node * temp;
    temp = head_2;

    while (temp -> next_node != NULL){
      temp = temp -> next_node;
    }

    temp -> next_node = newptr;
    newptr -> next_node = NULL;
  }
}



void create_list_A() {
  int n;
  printf("Enter the no. of elements in A to enter: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++){
    int value;
    scanf("%d", &value);
    push_into_A(value);
  }
}
void create_list_B() {
  int n;
  printf("Enter the no. of elements in B to enter: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++){
    int value;
    scanf("%d", &value);
    push_into_B(value);
  }
}



void display_list(node * head) {
  node * ptr = head;

  if (ptr == NULL){
    printf("Empty List\n");
  } else {
    while (ptr != NULL){
      printf("%d ", ptr -> data);
      ptr = ptr -> next_node;
    }
    printf("\n");
  }
}




int main () {

  create_list_A();
  create_list_B();

  display_list(head_1);
  display_list(head_2);

  concatenate(head_1, head_2);
  display_list(head);

  return 0;
}