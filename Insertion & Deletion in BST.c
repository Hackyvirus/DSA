#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *newNode(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void inOrder(Node * root){
  if(root!=NULL){
    inOrder(root->left);
    printf("%d \n",root->data);
    inOrder(root->right);
  }
}

Node * findMin(Node * root){
  while(root->left !=NULL){
    root = root->left;
  }
  return root;
}
Node * insert (Node * root, int data){
  if(root==NULL){
    return newNode(data);
  }
  if(root->data > data){
    root->left = insert(root->left,data);
  }else if(root->data < data){
    root->right = insert(root->right,data);
  }
  return root;
}

Node * deleteNode(Node * root, int data){
  if(root == NULL){
    return NULL;
  }
  if(data < root->data){
    root->left = deleteNode(root->left, data);
  }else if(data > root->data){
    root->right = deleteNode(root->right,data);
  }
  else{
    
    if(root->left == NULL && root->right == NULL){
      free(root);
      return NULL;
    }
   
    if(root->left == NULL){
      Node * temp = root->right;
      free(root);
      return temp;
    }else if(root->right == NULL){
      Node * temp = root->left;
      free(root);
      return temp;
    }
    
    Node * temp = findMin(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
    
  }
  
  return root;
  
}

int main() {
    Node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 1);
    insert(root, 4);
    insert(root, 7);
    insert(root, 2);
    inOrder(root);
    printf("\n");
    deleteNode(root,5);
    inOrder(root);
    
    return 0;
}
