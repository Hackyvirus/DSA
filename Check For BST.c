#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int data;
  struct Node * left;
  struct Node * right;
} Node;

Node * newNode(int data);
Node * newNode(int data){
  Node * newNode = (Node *) malloc (sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void PreOrder(Node * root);
void PreOrder(Node * root){
if(root != NULL){
    printf("%d ",root->data);
  PreOrder(root->left);
  PreOrder(root->right);
}
}

void PostOrder(Node * root);
void PostOrder(Node * root){
  if(root!= NULL){
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ",root->data);
  }
}

void InOrder(Node * root);
void InOrder(Node * root){
  if(root!= NULL){
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
  }
}

int isBST(Node * root);
int isBST(Node * root){
  static Node * prev = NULL;
  if(root != NULL){
    if(!isBST(root->left)){
      return 0;
  }
  if(prev != NULL && prev->data >= root->data){
    return 0;
  }
  prev = root;
  return isBST(root->right);
  }else{
    return 1;
  }
}



int main(){
  Node * root = (Node *) malloc(sizeof(Node));
  Node * second = (Node *) malloc(sizeof(Node));
  Node * third = (Node *) malloc(sizeof(Node));
  Node * fourth = (Node *) malloc(sizeof(Node));
  Node * fifth = (Node *) malloc(sizeof(Node));
  root = newNode(5);
  second = newNode(3);
  third = newNode(6);
  fourth = newNode(1);
  fifth = newNode(4);
  
  root->left = second;
  root->right = third;
  second->left = fourth;
  second->right = fifth;
  
  // PreOrder(root);
  // printf("\n");
  // PostOrder(root);
  // printf("\n");
  // InOrder(root);
  printf("\n");
  int i = isBST(root);
  printf("%d ",i);
  return 0;
}
