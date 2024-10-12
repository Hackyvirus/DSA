#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node * next;
} Node;

void travers ( Node * ptr);
void travers(Node * ptr){
  while(ptr != NULL){
    printf("The Current data is %d\n",ptr->data);
    ptr = ptr->next;
  }
}

Node * IB(Node * head, int data);
Node * IB(Node * head, int data){
  Node * newNode = (Node *) malloc( sizeof(Node));
  newNode->data = data;
  newNode->next = head;
  head= newNode ;
  return head;
}

Node * II(Node * head, int index, int data);
Node * II(Node * head, int index, int data){
  Node * newNode = (Node *) malloc (sizeof(Node));
  Node * ptr = head;
  int i = 0;
  while(i<index-1){
    ptr = ptr->next;
    i++;
  }
  newNode->data = data;
  newNode->next = ptr->next;
  ptr->next = newNode;
  return head;
}

Node * IL(Node * head, int data);
Node * IL(Node * head, int data){
  Node * newNode = (Node *) malloc(sizeof(Node));
  Node * ptr = head;
  while(ptr->next != NULL){
    ptr = ptr->next;
  }
  
  newNode->data = data;
  newNode->next = NULL;
  ptr->next = newNode;
  return head;
}

Node * IA(Node * head, Node * node, int data);
Node * IA(Node * head, Node * node, int data){
  Node * newNode = (Node *) malloc( sizeof(Node));
  newNode->data = data;
  newNode->next = node->next;
  node->next = newNode;
  return head;
}

// delete first 
Node * deleteFirst(Node * head);
Node * deleteFirst(Node * head){
  Node * ptr = head;
  head = head->next;
  free(ptr);
  return head;
}

//delete at index-1
Node * deleteatindex (Node * head, int index);
Node * deleteatindex ( Node * head, int index){
  Node * p = head;
  Node * q = head->next;
  
  for (int i = 0; i<index-1;i++){
    p = p->next;
    q = q->next;
  }
  p->next = q->next;
  free(q);
  return head;
}

// delete last Node
Node * deteleLastELement(Node * head);
Node* deteleLastELement(Node * head){
  Node * p = head;
  Node * q = head->next;
  while(q->next != NULL){
    p=p->next;
    q = q->next;
  }
  p->next = NULL;
  free(q);
  return head;
}

Node * deleteatValue( Node * head, int value);
Node * deleteatValue(Node * head, int value){
  Node * p = head;
  Node * q = head->next;
  while(q->data != value && q->next !=NULL){
    p = p->next;
    q = q->next;
  }
  if(q->data == value){
    p->next = q->next;
    free(q);
    return head;
  }
}

int main(){
  Node * head = (Node *) malloc (sizeof(Node));
  Node * second = (Node *) malloc (sizeof(Node));
  Node * third = (Node *) malloc (sizeof(Node));
  Node * fourth = (Node *) malloc (sizeof(Node));
  
  head->data = 1;
  head->next = second;
  second->data = 2;
  second->next = third;
  third->data = 3;
  third->next = fourth;
  fourth->data = 4;
  fourth->next = NULL;
  travers(head);
  printf("\n");
  // head= IB(head,5);
  // head= II(head,1,5);
  // head= IL(head,5);
  // head= IA(head,head,5);
  // head = deleteFirst(head);
  // head = deleteatindex(head,2);
  // head = deteleLastELement(head);
  // head = deleteatValue(head,4);
 travers(head);
}
