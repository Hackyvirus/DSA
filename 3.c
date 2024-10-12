// Insertion 
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node * next;
} Node;

void travers(Node * ptr);
void travers(Node * ptr){
  while(ptr != NULL){
    printf("The Data of Current Node %d\n",ptr->data);
    ptr = ptr->next;
  }
}

Node * atB(Node * head, int data);
Node * atB(Node * head, int data){
  Node * newNode = (Node *) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  return head;
}

Node * atI(Node * head, int data, int index);
Node * atI(Node * head, int data, int index){
  Node * newNode = (Node *) malloc(sizeof(Node));
  Node * ptr = head;
  int i = 0;
  while(i<index-1){
    ptr=ptr->next;
    i++;
  }
  newNode->next= ptr->next;
  newNode->data = data;
  ptr->next = newNode;
  return head;
}

Node * inE(Node * head, int data);
Node * inE(Node * head, int data){
  Node * newNode = (Node *) malloc (sizeof(Node));
  Node * ptr = head;
  newNode->data = data;
  
  while(ptr->next != NULL){
    ptr = ptr->next;
  }
  
  ptr->next = newNode;
  newNode->next = NULL;
  return head;
}

Node * AfterNode(Node * head, Node * node, int data);
Node * afteNode(Node * head, Node * node, int data){
  Node * newNode = (Node *) malloc (sizeof(Node));
  Node * ptr = head;
  newNode->data = data;
  
  newNode->next = node->next;
  node->next = newNode;
  return head;
}

int main()
{
  Node * head = (Node *) malloc(sizeof(Node));
  Node * second = (Node *) malloc(sizeof(Node));
  Node * third = (Node *) malloc(sizeof(Node));
  
  head->data = 1;
  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = NULL;
  travers(head);
  printf("\n");
  head = atB(head,4);
  head = atI(head,4,2);
  head = inE(head,4);
  head = afteNode(head,second,44);
  travers(head);
  return 0;
}
